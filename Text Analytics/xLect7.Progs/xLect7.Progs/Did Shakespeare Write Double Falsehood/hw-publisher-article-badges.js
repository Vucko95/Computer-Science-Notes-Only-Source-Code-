$(document).ready(function() {

$('div#pageid-content').each(function(i) {
  if($(this).hasClass('hw-pub-property-open_data') || $(this).hasClass('hw-pub-property-open_materials') || $(this).hasClass('hw-pub-property-preregistration') ){
      var opendata ="";
      var openmaterial ="";
      var preregistered="";
    if($(this).hasClass('hw-pub-property-open_data')){
      opendata = '<img title="The Open Data badge indicates that the study&#39;s data are publicly available in an open-access repository so that another researcher may reproduce the reported results." alt="Open Data" src="/publisher/icons/open-data.gif"/>';}
    if($(this).hasClass('hw-pub-property-open_materials')){
      openmaterial = '<img title="The Open Materials badge indicates that all components of the research methodology needed to reproduce the reported procedure and analysis are publicly available in an open-access repository." alt="Open Material" src="/publisher/icons/open-material.gif"/>';}
    if($(this).hasClass('hw-pub-property-preregistration')){
      preregistered = '<img title="The Preregistered badge indicates that the study&#39;s results are reported according to a publicly available preregistered design and analysis plan." alt="Preregistered" src="/publisher/icons/preregistered.gif"/>';}
    $(this).find('div.contributors').append('<div id="open-practices">' + opendata + openmaterial + preregistered +'</div>');
  }
});
});
