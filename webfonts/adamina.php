<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>Untitled Document</title>

<link href='http://fonts.googleapis.com/css?family=Adamina:400' rel='stylesheet' type='text/css'>
<link href='http://fonts.googleapis.com/css?family=Open+Sans:300,400' rel='stylesheet' type='text/css'>

<style type="text/css">

@charset "UTF-8";
/* CSS Document */

/* start Eric Meyer reset */
/* http://meyerweb.com/eric/tools/css/reset/ */
/* v1.0 | 20080212 */
html, body, div, span, applet, object, iframe, h1, h2, h3, h4, h5, h6, p, blockquote, pre,
a, abbr, acronym, address, big, cite, code, del, dfn, em, font, img, ins, kbd, q, s, samp,
small, strike, strong, sub, sup, tt, var, b, u, i, center, dl, dt, dd, ol, ul, li,
fieldset, form, label, legend, table, caption, tbody, tfoot, thead, tr, th, td {
	margin: 0;	padding: 0;	border: 0;	outline: 0;	font-size: 100%;	vertical-align: baseline;	background: transparent;}
body {	line-height: 1;}
ol, ul {	list-style: none;}
blockquote, q {	quotes: none;}
blockquote:before, blockquote:after,
q:before, q:after {	content: '';	content: none;}
/* remember to define focus styles! */
:focus {	outline: 0;}
/* remember to highlight inserts somehow! */
ins {	text-decoration: none;}
del {	text-decoration: line-through;}
/* tables still need 'cellspacing="0"' in the markup */
table {	border-collapse: collapse;	border-spacing: 0;}
/* end Eric Meyer reset */



body  {
	font: 75% Helvetica, Arial, sans-serif;
	background: #eae8e4;
	color: #000;
}

a	{
	text-decoration: none;
	font-weight: bold;
	color: #a6522e;
}

a:hover	{
	color: #4e3004;
}


.twoColFixLt #container { 
	width: 960px; 
	background: #fff;
	margin: 0 auto;
	padding: 0px 0px 20px 0px;
	text-align: left;
	-moz-box-shadow: 0px 0px 12px #aaa;
	-webkit-box-shadow: 0px 0px 12px #aaa;
	box-shadow: 0px 0px 12px #aaa;
	position: relative;
	top: -10px;
	left: 0;
}


#header	{
	margin: 10px;
	background: url(/images/header_bg_stripe.png) repeat-x bottom right;
}

#header img#logo	{
	padding-right: 20px;
	background: #fff;
}


#header div#donate a	{
	display: block;
	padding: 8px 0px 0px 0px;
	height: 49px;
	width: 189px;
	position: absolute;
	top: 36px;
	right: 18px;
	background: url(/images/donate_button.png) no-repeat top left;

	color: #c63403;
	text-transform: uppercase;
	font-size: 23px;
	font-weight: bold;
	text-align: right;
}
#header div#donate a span	{
	position: absolute;
	top: 6px;
	right: 31px;
	padding-right: 20px;
}

@-moz-document url-prefix() {
  #header div#donate a span {
     top: 8px;
	 right: 33px;}
}


#header div#donate a:hover	{
	background: url(/images/donate_button.png) no-repeat left -78px;
	color: #a83000;
}


.twoColFixLt #mainContent { 
	width: 780px;
	margin: 0 0 0 170px; 
	padding: 0px;
} 

.fltrt { /* this class can be used to float an element right in your page. The floated element must precede the element it should be next to on the page. */
	float: right;
	margin-left: 8px;
}

.fltlft { /* this class can be used to float an element left in your page */
	float: left;
	margin-right: 8px;
}

.clearfloat { /* this class should be placed on a div or break element and should be the final element before the close of a container that should fully contain a float */
	clear:both;
    height:0;
    font-size: 1px;
    line-height: 0px;
}
	
	

.twoColFixLt #sidebar1 {
	float: left; 
	width: 140px;
	margin: 0px 20px 20px 10px;
}
	
ul#leftNav	{
	margin: 0px;
	padding: 0px;
    }
	
ul#leftNav li	{
	border-bottom: solid 1px #d8cfb4;
	padding: 10px 0px;
    }



#sidebar1 div#loginArea	{
	position: absolute; bottom: -5px; left: 0px;
	width: 120px;
	margin: 10px;
	padding: 10px;
	color: #444;
	font-size: .9em;
	line-height: 2.5ex;
}
#sidebar1 div#loginArea span.button input	{
	background-color: #d8cfb4;
	color: #a15334;
	font-weight: bold;
	width: 95%;
	margin: 2px 0px 0px 0px;
	font-size: 1.1em;
	border: outset 1px #a15334;
}
	
#sidebar1 div#loginArea input	{
	width: 90%;
	margin: 2px auto;
}
	
#sidebar1 div#loginArea a	{
	display: block;
	font-weight: normal;
	margin: 5px 0px;
	border-bottom: solid 1px #d8cfb4;
}


div#aroundCarousel 	{
	border: solid 5px #464031;
    }
	
	
div#threeContentBoxes	{
}

div.contentBox	{
	height: 240px;
	width: 259px;
	float: left;
	margin: 2px 0px 0px 0px;
}

div.contentBox h2 a	{
	color: #4e3c14;
}
div.contentBox h2 a:hover	{
	color: #352503;
}


div.contentBox#box1 	{
	width: 260px;
	background: url(/images/ca_map_green.png) no-repeat top left;
}

div.contentBox#box2 	{
	border-left: solid 1px #e9e6d0;
	border-right: solid 1px #e9e6d0;
	background: url(/images/pampas_cutout.jpg) no-repeat center 72px;
}

div.contentBox#box3 	{
	border-right: none;
	margin-right: 0px;
	background: url(/images/flower_girl.jpg) no-repeat 112px 10px;
}


div.contentBox p	{
	padding: 5px 10px;
	color: #1f1f1f;
	font-size: 1.2em;
	line-height: 2.8ex;
	text-shadow: -2px 2px 2px rgba(255,255,255,0.9);  
}

div.contentBox#box1 p 	{
	text-align: right;
	margin-left: 100px;
}

div.contentBox#box3 p 	{
	margin-right: 80px;
}



div#footer	{
	width: 780px;
	margin-top: 244px;
	background-color: #4e3c14;
	color: #bcb093;
	font-size: .9em;
}

div#footer div#copyright	{
	display: inline-block;
	width: 370px;
	padding: 30px 10px 10px 10px;
}
div#footer div#footerNav	{
	display: inline-block;
	float: right;
	padding: 30px 10px 10px 10px;
}

div#footer a	{
	color: #c8af74;
}

div#footer a:hover	{
	color: #ffc;
}





#header p#tagline	{
	position: absolute;
	top: 10px;
	right: 20px;
	font-family: 'Open Sans', sans-serif;
	font-size: 18px;
	text-transform: uppercase;
	color: #4e3c14;
}


ul#leftNav a	{
	font-family: 'Adamina', sans-serif;
	font-size: 15px;
    }
	

	
div.contentBox h2	{
	background-color: #d9cfb4;
	color: #4e3c14;
	font-family: 'Adamina', sans-serif;
	font-size: 16px;
	padding: 1px 5px;
}
	

	
</style>

<!--[if IE 5]>
<style type="text/css"> 
/* place css box model fixes for IE 5* in this conditional comment */
.twoColFixLt #sidebar1 { width: 230px; }
</style>
<![endif]--><!--[if IE]>
<style type="text/css"> 
/* place css fixes for all versions of IE in this conditional comment */
.twoColFixLt #sidebar1 { padding-top: 30px; }
.twoColFixLt #mainContent { zoom: 1; }
/* the above proprietary zoom property gives IE the hasLayout it needs to avoid several bugs */
</style>
<![endif]-->

<link rel="stylesheet" href="/misc/agile_carousel/agile_carousel.css">

</head>

<body class="twoColFixLt">

<div id="container">

	<div id="header">
		<img id="logo" src="/images/logo_no_tagline.png" height="135" width="140" alt="PlantRight logo" />
		<p id="tagline">Stopping the sale of invasive plants in California</p>
		<div id="donate">
			<a href="donate.php">Donate Now</a>
		</div>
	</div>

	<div id="sidebar1">
	
	<ul id="leftNav">
	<li><a href="">About</a></li>
	<li><a href="">Invasive Plants &amp; Alternatives</a></li>
	<li><a href="">How to Help</a></li>
	<li><a href="">Resources</a></li>
	<li><a href="">For the Media</a></li>
	</ul>

	
	</div><!-- end #sidebar1 -->

	<div id="mainContent">

		<div id="aroundCarousel">
		
			<div class="slideshow" id="basic_slideshow"></div>
			
<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.6.0/jquery.js"></script>
<script src="/misc/agile_carousel/agile_carousel.alpha.js"></script>

<script>
    $.getJSON("/misc/agile_carousel/agile_carousel_data_pr.php", function (data) {
        $(document).ready(function () {
            $("#basic_slideshow").agile_carousel({
                carousel_data: data,
                carousel_outer_height: 283,
                carousel_height: 283,
                slide_height: 283,
                carousel_outer_width: 770,
                slide_width: 770,
                transition_type: "fade",
                timer: 4000
            });
        });
    });
</script>





		</div>


		<div id="threeContentBoxes">
		
			<div class="contentBox" id="box1">
			<h2><a href="">Invasives Where You Live</a></h2>
			<p>Use <a href="">our map</a> to see which plants to avoid, and which are safe &mdash; and beautiful &mdash; for your community.<br /><a href="">Start here</a></p>
			</div> 
			
			<div class="contentBox" id="box2">
			<h2><a href="">Invasives 101</a></h2>
			<p>Learn about the damage invasive plants cause California's landscapes and people. <a href="">More...</a></p>
			</div> 
			
			<div class="contentBox" id="box3">
			<h2><a href="">Benefits of Planting Right</a></h2>
			<p>PlantRight's alternatives not only behave well in the garden, the also support local businesses. <a href="">More...</a></p>
			</div> 
		
		</div>

		<div id="footer">
		
			<div id="copyright">&copy; 2007–2010 California Horticultural Invasives Prevention (Cal-HIP)</div>
			<div id="footerNav"><a href="">Contact Us</a> &nbsp;|&nbsp;  <a href="">Website feedback</a>  &nbsp;|&nbsp;   Site by <a href="">IBD</a> and <a href="">FILA Design</a></div>
		
		</div>

	</div><!-- end #mainContent -->


</div><!-- end #container -->

</div>
</body>
</html>