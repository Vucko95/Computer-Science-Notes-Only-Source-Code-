// $Id: googleanalytics.js,v 1.1.2.10 2009/03/15 20:32:21 hass Exp $

Drupal.gaTrackerAttach = function(context) {
  context = context || document;

  $('a', context).click( function() {
    var ga = Drupal.settings.googleanalytics;
    // Expression to check for absolute internal links.
    var isInternal = new RegExp("^(https?):\/\/" + window.location.host, "i");
    // Expression to check for special links like gotwo.module /go/* links.
    var isInternalSpecial = new RegExp("(\/go\/.*)$", "i");
    // Expression to check for download links.
    var isDownload = new RegExp("\\.(" + ga.trackDownloadExtensions + ")$", "i");

    try {
      // Is the clicked URL internal?
      if (isInternal.test(this.href)) {
        // Is download tracking activated and the file extension configured for download tracking?
        if (ga.trackDownload && isDownload.test(this.href)) {
          if (ga.LegacyVersion) {
            urchinTracker(this.href.replace(isInternal, ''));
          }
          else {
            // Download link clicked.
            var extension = isDownload.exec(this.href);
            pageTracker._trackEvent("Downloads", extension[1].toUpperCase(), this.href.replace(isInternal, ''));
          }
        }
        else if (isInternalSpecial.test(this.href)) {
          // Keep the internal URL for Google Analytics website overlay intact.
          if (ga.LegacyVersion) {
            urchinTracker(this.href.replace(isInternal, ''));
          }
          else {
            pageTracker._trackPageview(this.href.replace(isInternal, ''));
          }
        }
      }
      else {
        if (ga.trackMailto && $(this).is("a[@href^=mailto:]")) {
          // Mailto link clicked.
          if (ga.LegacyVersion) {
            urchinTracker('/mailto/' + this.href.substring(7));
          }
          else {
            pageTracker._trackEvent("Mails", "Click", this.href.substring(7));
          }
        }
        else if (ga.trackOutgoing) {
          // External link clicked. Clean and track the URL.
          if (ga.LegacyVersion) {
            urchinTracker('/outgoing/' + this.href.replace(/^(https?|ftp|news|nntp|telnet|irc|ssh|sftp|webcal):\/\//i, '').split('/').join('--'));
          }
          else {
            pageTracker._trackEvent("Outgoing links", "Click", this.href);
          }
        }
      }
    } catch(err) {}
  });
};

if (Drupal.jsEnabled) {
  $(document).ready(function() {
    Drupal.gaTrackerAttach(this);
  });
}
