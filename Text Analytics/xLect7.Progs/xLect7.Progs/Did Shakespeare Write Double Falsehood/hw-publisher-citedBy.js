function ajaxCompleteCitedBy(req, msg) {
   $('<img id="pdf-icon" src="/publisher/icons/pdf.png"/>').insertAfter($('a[rel="full-text.pdf"]'));
}

function addRelatedURLs(xhtmlData) {
	
	var cbA = $("#cb-loading-related-urls");
	if (gIsFrameset) {
		if (cbA.length) {
			updateCBItem(cbA, '<div id="cb-loaded-related-urls-none">Not available in this view</div>', false);
		}
	}
	else 
	if (xhtmlData && !(xhtmlData.indexOf('<span') >= 0)) {
		$("#related-urls").replaceWith(xhtmlData);
		var relatedWebPagesLabel = getSiteOption('relatedWebPagesLabel', 'Related Links');
		fixColHeights(1);
		if (cbA.length) {
			updateCBItem(cbA, '<a href="#related-urls"><b>' + relatedWebPagesLabel + '</b></a>', true);
		}
	}
	else {
		if (cbA.length) {
			updateCBItem(cbA, '<div id="cb-loaded-related-urls-none">No related web pages</div>', false);
		}
	}
}

$(document).ready(function () {
	$(".related-url-results li a").live ('click', function (e) {
		$(this).attr("target", "_blank");
		e.stopPropagation ();
	});
});
