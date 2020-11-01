


	// JAVA program for implementation of KMP pattern 
	// searching algorithm 
	  
	class KMPsearch { 
	    void KMPSearch(String pat, String txt) 
	    { 
	        int M = pat.length(); 
	        int N = txt.length(); 
	  
	        // create lps[] that will hold the longest 
	        // prefix suffix values for pattern 
	        int lps[] = new int[M]; 
	        int j = 0; // index for pat[] 
	  
	        // Preprocess the pattern (calculate lps[] 
	        // array) 
	        computeLPSArray(pat, M, lps); 
	  
	       //insert your code here
	        
	    } 
	  
	    void computeLPSArray(String pat, int M, int lps[]) 
	    { 
	        // length of the previous longest prefix suffix 
	        int len = 0; 
	        int i = 1; 
	        lps[0] = 0; // lps[0] is always 0 
	  
	        // the loop calculates lps[i] for i = 1 to M-1 
	        while (i < M) { 
	            if (pat.charAt(i) == pat.charAt(len)) { 
	                len++; 
	                lps[i] = len; 
	                i++; 
	            } 
	            else // (pat[i] != pat[len]) 
	            { 
	                // This is tricky. Consider the example. 
	                // AAACAAAA and i = 7. The idea is similar 
	                // to search step. 
	                if (len != 0) { 
	                    len = lps[len - 1]; 
	  
	                    // Also, note that we do not increment 
	                    // i here 
	                } 
	                else // if (len == 0) 
	                { 
	                    lps[i] = len; 
	                    i++; 
	                } 
	            } 
	        } 
	    } 
	  
	    // Driver program to test above function 
	    public static void main(String args[]) 
	    { 
	        String txt = "ABABDABACDABABCABAB"; 
	        String pat = "ABABCABAB"; 
	        new KMPsearch().KMPSearch(pat, txt); 
	    } 
	} 