var engine=new Array();
var q_var=new Array();
engine[0]="google";	q_var[0]="q";
engine[1]="yahoo";	q_var[1]="p";
engine[2]="msn";	q_var[2]="q";
engine[3]="aol";	q_var[3]="query";
engine[4]="aol";	q_var[4]="encquery";
engine[5]="lycos";	q_var[5]="query";
engine[6]="ask";	q_var[6]="q";
engine[7]="altavista";	q_var[7]="q";
engine[8]="netscape";	q_var[8]="query";
engine[9]="cnn";	q_var[9]="query";
engine[10]="looksmart";	q_var[10]="qt";
engine[11]="about";	q_var[11]="terms";
engine[12]="mamma";	q_var[12]="query";
engine[13]="alltheweb";	q_var[13]="q";
engine[14]="gigablast";	q_var[14]="q";
engine[15]="voila";	q_var[15]="rdata";
engine[16]="virgilio";	q_var[16]="qs";
engine[17]="live";	q_var[17]="q";
engine[18]="baidu";	q_var[18]="wd";
engine[19]="alice";	q_var[19]="qs";
engine[20]="yandex";	q_var[20]="text";
engine[21]="najdi";	q_var[21]="q";
engine[22]="aol";	q_var[22]="q";
engine[23]="club-internet"; q_var[23]="query";
engine[24]="mama";	q_var[24]="query";
engine[25]="seznam";	q_var[25]="q";
engine[26]="search";	q_var[26]="q";
engine[27]="wp";	q_var[27]="szukaj";
engine[28]="onet";	q_var[28]="qt";
engine[29]="netsprint";	q_var[29]="q";
engine[30]="google.interia";	q_var[30]="q";
engine[31]="szukacz";	q_var[31]="q";
engine[32]="yam";	q_var[32]="k";
engine[33]="pchome";	q_var[33]="q";
engine[34]="kvasir";	q_var[34]="searchExpr";
engine[35]="sesam";	q_var[35]="q";
engine[36]="ozu"; q_var[36]="q";
engine[37]="terra"; q_var[37]="query";
engine[38]="nostrum"; q_var[38]="query";
engine[39]="mynet"; q_var[39]="q";
engine[40]="ekolay"; q_var[40]="q";
engine[41]="search.ilse"; q_var[41]="search_for";
engine[42]="bing"; q_var[42]="q";


var queryStr="";
var doc=document;
var ref_url=doc.referrer; 
//check if from same domain
if (!ref_url) { ref_url=""; }
else {
	dm=doc.domain;
	p=ref_url.indexOf(dm);
	if ((p>=0) && (p<=8)) { ref_url=""; }
	if (ref_url.indexOf("[")==0 && ref_url.lastIndexOf("]")==(ref_url.length-1)) { ref_url=""; }
}

//check if the referrer come from SE

if (uRef()){
	if(uOrg() && uOrg().length>0){
		queryStr=queryStr+uOrg();	
		var metadesc = getDesc();
		var _t="";
		if(doc.title || doc.title.length>0)
			_t = doc.title;

		var _u = encodeURIComponent(doc.location);

		var url = "http://client.heystaks.com/HeyStaks_Web/tbc?action=autostak&a="+_ac+"&stakid="+_sid+"&url="+_u+"&title="+_t+"&username="+_un
			  +"&password="+_pa+"&passhashed=true&query="+queryStr+"&"+metadesc;
		
		req = new XMLHttpRequest();
		req.open("GET", url, true);	
		req.send();
	}
}


function getDesc(){
	  var metas = document.getElementsByTagName("meta");
	  var type;
	  
	  mLen=metas.length;
	  var keywords="";
	  var desc="";
	  for(var i=0;i<mLen;i++){
		type=""
		if (metas[i].getAttribute("name"))
			  type=metas[i].getAttribute("name").toLowerCase();
		if(type.length>0 && type=="description"){
		   desc=desc + " " + metas[i].getAttribute("content");
		   
		}
	    	
	    if(type.length>0  && type=="keywords"){
	    	keywords=keywords + " " +metas[i].getAttribute("content");
		
	    } 
	  }
	 desc=encodeURIComponent(desc);
	 keywords=encodeURIComponent(keywords);
	 returnStr="snippet="+desc+"&tags="+keywords;
	 return returnStr;
}
function uRef() {
	if (ref_url=="0" || ref_url=="" || ref_url=="-") return "";
	var i=0,h,k,n;
	if ((i=ref_url.indexOf("://"))<0 || uGCse()) return "";
	h=ref_url.substring(i+3,ref_url.length);
	if (h.indexOf("/") > -1) {
		k=h.substring(h.indexOf("/"),h.length);
		if (k.indexOf("?") > -1) k=k.substring(0,k.indexOf("?"));
		h=h.substring(0,h.indexOf("/"));
	}
	h=h.toLowerCase();
	n=h;
	if ((i=n.indexOf(":")) > -1) n=n.substring(0,i);
	if (h.indexOf("www.")==0) h=h.substring(4,h.length);
	for (var ii=0;ii<engine.length;ii++) {
		var k="";
		if (h.toLowerCase().indexOf(engine[ii].toLowerCase()) > -1 || n.toLowerCase().indexOf(engine[ii].toLowerCase() >-1)){
			return true;
		}
	}
}
function uOrg() {
	var returnSt="";
	if (ref_url=="0" || ref_url=="" || ref_url=="-") return "";
	var i=0,h,k;
	if ((i=ref_url.indexOf("://"))<0 || uGCse()) return "";
	h=ref_url.substring(i+3,ref_url.length);
	if (h.indexOf("/") > -1) {
		h=h.substring(0,h.indexOf("/"));
	}
	for (var ii=0;ii<engine.length;ii++) {
		var k="";
		if (h.toLowerCase().indexOf(engine[ii].toLowerCase()) > -1) {
			if ((i=ref_url.indexOf("?"+q_var[ii]+"=")) > -1 || (i=ref_url.indexOf("&"+q_var[ii]+"=")) > -1) {
				k=ref_url.substring(i+q_var[ii].length+2,ref_url.length);
				
				if ((i=k.indexOf("&")) > -1) k=k.substring(0,i);
				k=encodeURIComponent(k);
				returnStr= k+"&we="+engine[ii].toLowerCase();
				return returnStr;
				
				
			}
		}
	}
	return "";
	
}
function uGCse() {
	var h,p;
	h=p=ref_url.split("://")[1];
	if(h.indexOf("/")>-1) {
		h=h.split("/")[0];
		p=p.substring(p.indexOf("/")+1,p.length);
	}
	if(p.indexOf("?")>-1) {
		p=p.split("?")[0];
	}
	if(h.toLowerCase().indexOf("google")>-1) {
		if(ref_url.indexOf("?q=")>-1 || ref_url.indexOf("&q=")>-1) {
			if (p.toLowerCase().indexOf("cse")>-1) {
				return true;
			}
		}
	}
}
