/* global definitions, overrides, and functions common to SAGE Publication sites */

//gSiteOptions.suppressDockedSearchNav = false;
gSiteOptions.authAffilMatch = 'div.article div.contributors:not(.intlv) ol.affiliation-list';
gSiteOptions.authAffilDisableMultipleMatches = true;
gSiteOptions.enableCCIcons = true;

// This injects custom css into the page if a leaderboard ad is present
gSiteOptions[ 'bam-ads'][ 'custom-css'][ 'leaderboard'] = '/publisher/css/hw-publisher-leaderboard.css';

$(document).ready(function () {
  var histLinks = $("div.search-history-links");
  if (histLinks.length) {
    histLinks.css("display", "block");
    $("div.search-history-links form input[name='submit']").hide();
    var runForm = $("div.search-history-links div.run-last-search-inputs").parent("form");
    var runSpan = $("div.search-history-links span#srchhist-run-last");
    var editForm = $("div.search-history-links div.edit-last-search-inputs").parent("form");
    var editSpan = $("div.search-history-links span#srchhist-edit-last");
    if (runForm.length && runSpan.length) {
      var linkText = runSpan.attr('title');
      runSpan.replaceWith('<a href="#" id="srchhist-run-last-link">&#171; ' + linkText + '<\/a>')
      $("#srchhist-run-last-link").click(function (e) {
        runForm.find("input[name='submit']").click();
        e.preventDefault();
      });
    }
    if (editForm.length && editSpan.length) {
      var linkText = editSpan.attr('title');
      editSpan.replaceWith('<a href="#" id="srchhist-edit-last-link">' + linkText + '<\/a>')
      $("#srchhist-edit-last-link").click(function (e) {
        editForm.find("input[name='submit']").click();
        e.preventDefault();
      });
    }
  }
  /****************************
  QB:#31150 pdf icons BEGIN
  ****************************/
  var pdfLen = $('a[rel="full-text.pdf"]');
  if (pdfLen.length) {
    insPDFIconAfter('a[rel="full-text.pdf"]');
  }
  // for the outliers, spsph, amjsports
  var pdfLen = $('a[rel="view-full-text.pdf"] + span.free');
  if ($('a[rel="view-full-text.pdf"]').length) {
    if (pdfLen.length) {
      insPDFIconBefore('a[rel="view-full-text.pdf"]+span.free');
    } else {
      insPDFIconAfter('a[rel="view-full-text.pdf"]');
    }
  }
  // For Outlier pdf view
  if ($('span.variant-indicator span').html() == "Full Text (PDF)") {
    if ($('span.variant-indicator').length) {
      if ($('span.variant-indicator + span.free').length) {
        insPDFIconBefore('span.variant-indicator + span.free');
      } else {
        insPDFIconAfter('span.variant-indicator span');
      }
    }
  }
  /****************************
  QB:#31150 pdf icons END
  ****************************/
  var soclinks = $('li.social-bookmarking-item a');
  if (soclinks.length) {
    soclinks.attr('rel', 'external-nw');
    /* QB:37398 */
    linkNewWin(soclinks);
  }
  
  $(".openaccess a[rel='full-text']").text("Free Full Text");
  $(".openaccess a[rel='full-text.pdf']").text("Free Full \(PDF\)");
  updateFormInput("#header-search-label", "#header-input", '', '');
  $('form#portal-qs-form').submit(function (e) {
    return (doSearch("#header-search-label", "#header-input"));
  });
  $('form#journal-qs-form,').submit(function (e) {
    return (doSearch("#header-qs-search-label", "#header-qs-input"));
  });
  $('form#portal-qs-form').click(function (e) {
    return (doSearch("#header-search-label", "#header-input"));
  });
  $('form#journal-qs-form,').click(function (e) {
    return (doSearch("#header-qs-search-label", "#header-qs-input"));
  });
  $('form#sagepub-qs-form').submit(function (e) {
    return (doSearch("#header-qs-search-label", "#header-qs-input"));
  });
  $('form#sagepub-qs-form,').click(function (e) {
    return (doSearch("#header-qs-search-label", "#header-qs-input"));
  });
  
  /* Marked citation redesign: 6/4/2012 */
  var generalMC = $('div#col-2 div.marked-citation');
  var srchMC = $('div#col-2 div.search-results-mc-plus-search-nav');
  var topPadding = 15;
  
  if (generalMC.length && ! $("#pageid-search-results").length) {
    var myoffset = generalMC.offset();
    var defaultDockedNavRules =[
    '', '$(#col-2 .marked-citation > *)'];
    setupDockBlock(2, 'mc-docked-nav', 'sidebar marked-citation', defaultDockedNavRules);
  }
  if (srchMC.length) {
    var srchoffset = srchMC.offset();
    var defaultDockedNavRules =[
    '', '$(#col-2 .search-results-mc-plus-search-nav > *)'];
    setupDockBlock(2, 'mc-docked-nav', 'search-results-mc-plus-search-nav', defaultDockedNavRules);
  }

	if (($('div#impact-factor div#impact-factor-row div#if-left').text().length == 0 ) &&
		 ($('div#impact-factor div#impact-factor-row div#if-right').text().length == 0))
		 {
    		$('div#impact-factor').remove();
	  }
	$('div#content-block ul.cit-list div.cit-extra span.cit-flags span').each(
   function(i) {
    if ($(this).text().length == 0 ) {
    		$(this).remove();
	  }
    });
});

function poptoggle(postid) {
  var whichpost = document.getElementById(postid);
  if (whichpost.className == "expandblock") {
    document.getElementById('p' + postid).src = '/publisher/icons/plus.png';
    whichpost.className = "collapseblock";
  } else {
    whichpost.className = "expandblock";
    document.getElementById('p' + postid).src = '/publisher/icons/minus.png';
  }
}
function setupCollapsibles() {
  prepCollapsibles("div.content-box div.collapsible, #col-3 .collapsible");
}
function doSearch(labelMatchString, inputMatchString) {
  
  var label = $(labelMatchString);
  var iStr = 'input' + inputMatchString;
  var input = $(iStr);
  var text = label.text().toLowerCase();
  var PhqsText = input.val().toLowerCase();
  
  if ((PhqsText == text) || (PhqsText == undefined) || (PhqsText == '')) {
    return false;
  } else {
    return true;
  }
}
function insPDFIconAfter(elem) {
  local_elem = elem + ' img.pdf-icon';
  
  if ($(local_elem.length < 0)) {
    $('<img id="pdf-icon" src="/publisher/icons/pdf.png"/>').insertAfter($(elem));
  }
}
function insPDFIconBefore(elem) {
  local_elem = 'img.pdf-icon ' + elem;
  
  if ($(local_elem.length < 0)) {
    $('<img id="pdf-icon" src="/publisher/icons/pdf.png"/>').insertBefore($(elem));
  }
}
function CheckAll(event, tag, flag) {
  event.preventDefault();
  tag.each(function () {
    $(this).attr('checked', flag);
  });
}
function addToMyCit(event) {
  event.preventDefault();
  $("#content-block form div.gca-buttons:first-child").find('input[name=submit]').click();
  	return false;
}
function resultsMC(event) {
	event.preventDefault();
	$("#results-gca-form").find('input[name=submit]').click();
	return false;
}

$(window).load(function() {
fixColHeights(1);
});


