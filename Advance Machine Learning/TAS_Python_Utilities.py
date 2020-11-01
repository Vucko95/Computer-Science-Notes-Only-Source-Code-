###################################
#
# THE ANALYTICS STORE
#
# Python Programming For Data Analytics
#
# Utility Functions
#
###################################

import os
import subprocess
from IPython.display import display, HTML, Image
import io as io

import pandas
import numpy as np
import matplotlib.pyplot as plt
from sklearn.tree import export_graphviz

def data_viz(df):
    # Plot histograms for numeric columns
    for idx, col in enumerate(df.select_dtypes(include=[np.number]).keys()):
        df[col].plot.hist(title = col)
        plt.show()

    # Plot bar plots  for categorical/boolean columns        
    for idx, col in enumerate(df.select_dtypes(include=[np.object, np.bool]).keys()):
        # Only draw bar plots for variables with less than 30 levels
        if len(df[col].unique()) < 30:
            df[col].value_counts().plot.bar(title = col)
            plt.show()


def data_viz_target(df, target_feat):

	num_target_levels = len(df[target_feat].unique())

	for c in list(df.select_dtypes(include=[np.number]).keys()):
	    print(c)
	    df.hist(column = c, by=target_feat, figsize=(14, 4), sharey=True, sharex=True, layout = (1, num_target_levels), normed = True, bins = 20)
	    plt.show()
	
	for c in list(df.select_dtypes(include=[np.object]).keys()):
	    # Calculate a max value for frequencies
	    x_max = df[c].value_counts().max()
	
	    # Create a canvas
	    plt.figure(figsize=(14, 5))
	
	    # Insert a subplot in a 2 by 2 grid at position 1
	    plt.subplot(1, num_target_levels, 1)
	
	    print(c)
	    # Loop through the occupations
	    for idx, clus in enumerate(df[target_feat].unique()):
	        plt.subplot(1, num_target_levels,idx + 1)
	        df.loc[df[target_feat] == clus, c].value_counts(normalize=True).sort_index().plot(kind = "barh", title = "Target: " + str(clus))
	
	
	    # Causes the pliots to be spaced properly so axes etc don't overlap
	    plt.tight_layout()
	    plt.show()

# Method for drawing nice decision trees (requires the dot language)
# This is a utility method that draws nice decision trees for us. From http://chrisstrelioff.ws/sandbox/2015/06/08/decision_trees_in_python_with_scikit_learn_and_pandas.html
def visualize_tree(tree, feature_names, fileName="dt.png"):
    """Create tree png using graphviz.

    Args
    ----
    tree -- scikit-learn DecsisionTree.
    feature_names -- list of feature names.
    """
    with open("dt.dot", 'w') as f:
        export_graphviz(tree, out_file=f,
                        feature_names=feature_names)

    command = ["dot", "-Tpng", "dt.dot", "-o", fileName]
    try:
        subprocess.check_call(command)
    except:
        exit("Could not run dot, ie graphviz, to "
             "produce visualization")