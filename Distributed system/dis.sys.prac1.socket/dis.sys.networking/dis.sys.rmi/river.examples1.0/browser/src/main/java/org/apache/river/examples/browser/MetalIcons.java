/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.apache.river.examples.browser;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Graphics;
import javax.swing.plaf.metal.MetalLookAndFeel;
import java.io.Serializable;
import javax.swing.Icon;

/**
 * Based on "MetalIconFactory.java"
 *
 * @author Sun Microsystems, Inc.
 *
 */
class MetalIcons implements Serializable {

  private static Icon blueFolderIcon;
  private static Icon blueFileIcon;
  private static Icon orangeFolderIcon;
  private static Icon orangeFileIcon;
  private static Icon grayFolderIcon;
  private static Icon grayFileIcon;
  private static Icon unusableFolderIcon;
  private static Icon unusableFileIcon;

  // Colors for Orange icons
  private static Color orangeDarkShadowColor = new Color(0xcc, 0x99, 0x66);
  private static Color orangeColor           = new Color(0xff, 0x99, 0x33);
  private static Color orangeShadowColor     = new Color(0xcc, 0x99, 0x66);
  private static Color orangeInfoColor       = new Color(0x99, 0x00, 0x33);
  private static Color orangeHighlightColor  = new Color(0xff, 0xff, 0x33);

  // Colors for Gray icons
  private static Color grayDarkShadowColor = new Color(0x99, 0x99, 0x99);
  private static Color grayColor           = new Color(0xbb, 0xbb, 0xbb);
  private static Color grayShadowColor     = new Color(0xaa, 0xaa, 0xaa);
  private static Color grayInfoColor       = new Color(0x88, 0x88, 0x88);
  private static Color grayHighlightColor  = new Color(0xdd, 0xdd, 0xdd);

  // Constants
  public static final boolean DARK = false;
  public static final boolean LIGHT = true;

  // Accessor functions for Icons. Does the caching work.
  public static Icon getBlueFolderIcon() {
    if(blueFolderIcon == null)
      blueFolderIcon = new BlueFolderIcon();
    return blueFolderIcon;
  }

  public static Icon getBlueFileIcon() {
    if(blueFileIcon == null)
      blueFileIcon = new BlueFileIcon();
    return blueFileIcon;
  }

  public static Icon getOrangeFolderIcon() {
    if(orangeFolderIcon == null)
      orangeFolderIcon = new OrangeFolderIcon();
    return orangeFolderIcon;
  }

  public static Icon getOrangeFileIcon() {
    if(orangeFileIcon == null)
      orangeFileIcon = new OrangeFileIcon();
    return orangeFileIcon;
  }

  public static Icon getGrayFolderIcon() {
    if(grayFolderIcon == null)
      grayFolderIcon = new GrayFolderIcon();
    return grayFolderIcon;
  }

  public static Icon getGrayFileIcon() {
    if(grayFileIcon == null)
      grayFileIcon = new GrayFileIcon();
    return grayFileIcon;
  }

  public static Icon getUnusableFolderIcon() {
    if(unusableFolderIcon == null)
      unusableFolderIcon = new UnusableFolderIcon();
    return unusableFolderIcon;
  }

  public static Icon getUnusableFileIcon() {
    if(unusableFileIcon == null)
      unusableFileIcon = new UnusableFileIcon();
    return unusableFileIcon;
  }


  static private final Dimension folderIcon16Size = new Dimension( 16, 16 );
  static private final Dimension fileIcon16Size = new Dimension( 16, 16 );

  /**
   */
  static class BlueFolderIcon extends FolderIcon16 implements Icon {
    public void paintIcon(Component c, Graphics g, int x, int y) {
      super.paintIcon(c, g, x, y,
		      MetalLookAndFeel.getPrimaryControlDarkShadow(),
		      MetalLookAndFeel.getPrimaryControl(),
		      MetalLookAndFeel.getPrimaryControlShadow(),
		      MetalLookAndFeel.getPrimaryControlInfo(),
		      MetalLookAndFeel.getPrimaryControlHighlight());
    }
    public int getShift() { return -1; }
    public int getAdditionalHeight() { return 2; }
  }

  static class OrangeFolderIcon extends FolderIcon16 implements Icon {
    public void paintIcon(Component c, Graphics g, int x, int y) {
      super.paintIcon(c, g, x, y,
		      orangeDarkShadowColor,
		      orangeColor,
		      orangeShadowColor,
		      orangeInfoColor,
		      orangeHighlightColor);
    }
    public int getShift() { return -1; }
    public int getAdditionalHeight() { return 2; }
  }

  static class GrayFolderIcon extends FolderIcon16 implements Icon {
    public void paintIcon(Component c, Graphics g, int x, int y) {
      super.paintIcon(c, g, x, y,
		      grayDarkShadowColor,
		      grayColor,
		      grayShadowColor,
		      grayInfoColor,
		      grayHighlightColor);
    }
    public int getShift() { return -1; }
    public int getAdditionalHeight() { return 2; }
  }

  static class UnusableFolderIcon extends FolderIcon16 implements Icon {
    public void paintIcon(Component c, Graphics g, int x, int y) {
      super.paintIcon(c, g, x, y,
		      grayDarkShadowColor,
		      grayColor,
		      grayShadowColor,
		      grayInfoColor,
		      grayHighlightColor);
      super.drawCross(c, g, x, y);
    }
    public int getShift() { return -1; }
    public int getAdditionalHeight() { return 2; }
  }

  /**
   */
  private static abstract class FolderIcon16 implements Serializable {

    public void paintIcon(Component c, Graphics g, int x, int y,
			  Color controlDarkShadowColor,
			  Color controlColor,
			  Color controlShadowColor,
			  Color controlInfoColor,
			  Color controlHighlightColor) {
      g.translate( x, y + getShift() );

      int right = folderIcon16Size.width - 1;
      int bottom = folderIcon16Size.height - 1;

      // Draw tab top
      g.setColor( controlDarkShadowColor );
      g.drawLine( right - 5, 3, right, 3 );
      g.drawLine( right - 6, 4, right, 4 );

      // Draw folder front
      g.setColor( controlColor );
      g.fillRect( 2, 7, 13, 8 );

      // Draw tab bottom
      g.setColor( controlShadowColor );
      g.drawLine( right - 6, 5, right - 1, 5 );

      // Draw outline
      g.setColor( controlInfoColor );
      g.drawLine( 0, 6, 0, bottom );            // left side
      g.drawLine( 1, 5, right - 7, 5 );         // first part of top
      g.drawLine( right - 6, 6, right - 1, 6 ); // second part of top
      g.drawLine( right, 5, right, bottom );    // right side
      g.drawLine( 0, bottom, right, bottom );   // bottom

      // Draw highlight
      g.setColor( controlHighlightColor );
      g.drawLine( 1, 6, 1, bottom - 1 );
      g.drawLine( 1, 6, right - 7, 6 );
      g.drawLine( right - 6, 7, right - 1, 7 );

      g.translate( -x, -(y + getShift()) );
    }

    public void drawCross(Component c, Graphics g, int x, int y) {
      g.translate( x, y + getShift() );

      int right = folderIcon16Size.width - 1;
      int bottom = folderIcon16Size.height - 1;

      // Draw tab top
      Color crossColor = Color.red;
      g.setColor( crossColor );
      g.drawLine( 2, 2, right, bottom );
      g.drawLine( 2, bottom, right, 2 );
    }

    public int getShift() { return 0; }
    public int getAdditionalHeight() { return 0; }

    public int getIconWidth() { return folderIcon16Size.width; }
    public int getIconHeight() { return folderIcon16Size.height + getAdditionalHeight(); }
  }




  static class BlueFileIcon extends FileIcon16 implements Icon {
    public void paintIcon(Component c, Graphics g, int x, int y) {
      super.paintIcon(c, g, x, y,
		      MetalLookAndFeel.getPrimaryControlHighlight(),
		      MetalLookAndFeel.getPrimaryControlInfo(),
		      MetalLookAndFeel.getPrimaryControl());
    }
    public int getShift() { return -1; }
    public int getAdditionalHeight() { return 2; }
  }

  static class OrangeFileIcon extends FileIcon16 implements Icon {
    public void paintIcon(Component c, Graphics g, int x, int y) {
      super.paintIcon(c, g, x, y,
		      orangeHighlightColor,
		      orangeInfoColor,
		      orangeColor);
    }
    public int getShift() { return -1; }
    public int getAdditionalHeight() { return 2; }
  }

  static class GrayFileIcon extends FileIcon16 implements Icon {
    public void paintIcon(Component c, Graphics g, int x, int y) {
      super.paintIcon(c, g, x, y,
		      grayHighlightColor,
		      grayInfoColor,
		      grayColor);
    }
    public int getShift() { return -1; }
    public int getAdditionalHeight() { return 2; }
  }

  static class UnusableFileIcon extends FileIcon16 implements Icon {
    public void paintIcon(Component c, Graphics g, int x, int y) {
      super.paintIcon(c, g, x, y,
		      grayHighlightColor,
		      grayInfoColor,
		      grayColor);
      super.drawCross(c, g, x, y);
    }
    public int getShift() { return -1; }
    public int getAdditionalHeight() { return 2; }
  }

  /**
   */
  private static abstract class FileIcon16 implements Serializable {
    public void paintIcon(Component c, Graphics g, int x, int y,
			  Color controlHighlightColor,
			  Color controlInfoColor,
			  Color controlColor) {
      g.translate( x, y + getShift() );

      int right = fileIcon16Size.width - 1;
      int bottom = fileIcon16Size.height - 1;

      // Draw fill
      g.setColor( controlHighlightColor );
      g.fillRect( 4, 2, 9, 12 );

      // Draw frame
      g.setColor( controlInfoColor );
      g.drawLine( 2, 0, 2, bottom );                 // left
      g.drawLine( 2, 0, right - 4, 0 );              // top
      g.drawLine( 2, bottom, right - 1, bottom );    // bottom
      g.drawLine( right - 1, 6, right - 1, bottom ); // right
      g.drawLine( right - 6, 2, right - 2, 6 );      // slant 1
      g.drawLine( right - 5, 1, right - 4, 1 );      // part of slant 2
      g.drawLine( right - 3, 2, right - 3, 3 );      // part of slant 2
      g.drawLine( right - 2, 4, right - 2, 5 );      // part of slant 2

      // Draw highlight
      g.setColor( controlColor );
      g.drawLine( 3, 1, 3, bottom - 1 );                  // left
      g.drawLine( 3, 1, right - 6, 1 );                   // top
      g.drawLine( right - 2, 7, right - 2, bottom - 1 );  // right
      g.drawLine( right - 5, 2, right - 3, 4 );           // slant
      g.drawLine( 3, bottom - 1, right - 2, bottom - 1 ); // bottom

      g.translate( -x, -(y + getShift()) );
    }

    public void drawCross(Component c, Graphics g, int x, int y) {
      g.translate( x, y + getShift() );

      int right = folderIcon16Size.width - 1;
      int bottom = folderIcon16Size.height - 1;

      // Draw tab top
      Color crossColor = Color.red;
      g.setColor( crossColor );
      g.drawLine( 1, 1, right - 1, bottom - 1 );
      g.drawLine( 1, bottom - 1, right - 1, 1 );
    }

    public int getShift() { return 0; }
    public int getAdditionalHeight() { return 0; }

    public int getIconWidth() { return fileIcon16Size.width; }
    public int getIconHeight() { return fileIcon16Size.height + getAdditionalHeight(); }
  }


  static class TreeLeafIcon extends FileIcon16 {
    public int getShift() { return 2; }
    public int getAdditionalHeight() { return 4; }
  }
}

