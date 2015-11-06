$(document).ready( function() {
	$("#btn_home").click(function(e) {
		e.stopPropagation();
		e.preventDefault();
	    $('html, body').animate({ scrollTop: 0 }, 1000);
	});
	$("#brand").click(function(e) {
		e.stopPropagation();
		e.preventDefault();
	    $('html, body').animate({ scrollTop: 0 }, 1000);
	});
	$("#btn_about, #btn_about2").click(function(e) {
		e.stopPropagation();
		e.preventDefault();
	    $('html, body').animate({ scrollTop: $("#about").offset().top }, 1000);
	});
	$("#btn_result").click(function(e) {
		e.stopPropagation();
		e.preventDefault();
	    $('html, body').animate({ scrollTop: $("#result").offset().top }, 1000);
	});
	$("#btn_school").click(function(e) {
		e.stopPropagation();
		e.preventDefault();
	    $('html, body').animate({ scrollTop: $("#school").offset().top }, 1000);
	});
	$("#btn_rank, #btn_rank2").click(function(e) {
		e.stopPropagation();
		e.preventDefault();
	    $('html, body').animate({ scrollTop: $("#rank").offset().top }, 1000);
	});
	$("#btn_test").click(function(e) {
		e.stopPropagation();
		e.preventDefault();
	    $('html, body').animate({ scrollTop: $("#test").offset().top }, 1000);
	});
	$("#btn_map").click(function(e) {
		e.stopPropagation();
		e.preventDefault();
	    $('html, body').animate({ scrollTop: $("#map").offset().top }, 1000);
	});
	$("#btn_faq").click(function(e) {
		e.stopPropagation();
		e.preventDefault();
	    $('html, body').animate({ scrollTop: $("#faq").offset().top }, 1000);
	});
	$("#btn_contact").click(function(e) {
		e.stopPropagation();
		e.preventDefault();
	    $('html, body').animate({ scrollTop: $("#contact").offset().top }, 1000);
		$("#btn_contact").attr("class","active");
	});
	$(window).scroll( function(){
		var t=document.documentElement.scrollTop || document.body.scrollTop;
		var b=document.documentElement.scrollBottom || document.body.scrollBottom;
		var HOME = 0;
		var ABOUT = $("#about").offset().top;
		var RESULT = $("#result").offset().top;
		var MAP = $("#map").offset().top;
		var FAQ = $("#faq").offset().top;
		var SCHOOL = $("#school").offset().top;
		var RANK = $("#rank").offset().top;
		var TEST = $("#test").offset().top;
		var CONTACT = $("#contact").offset().top;
		CONTACT = CONTACT - $(window).height();
		if(t+1>=CONTACT){
			$("#btn_contact").attr("class","active");
			$("#btn_faq").attr("class","");
			$("#btn_map").attr("class","");
			$("#btn_test").attr("class","");
			$("#btn_rank").attr("class","");
			$("#btn_school").attr("class","");
			$("#btn_result").attr("class","");
			$("#btn_about").attr("class","");
			$("#btn_home").attr("class","");
		}
		else if(t+1>=TEST){
			$("#btn_contact").attr("class","");
			$("#btn_faq").attr("class","");
			$("#btn_map").attr("class","");
			$("#btn_test").attr("class","active");
			$("#btn_rank").attr("class","");
			$("#btn_school").attr("class","");
			$("#btn_result").attr("class","");
			$("#btn_about").attr("class","");
			$("#btn_home").attr("class","");
		}
		else if(t+1>=RANK){
			$("#btn_contact").attr("class","");
			$("#btn_faq").attr("class","");
			$("#btn_map").attr("class","");
			$("#btn_test").attr("class","");
			$("#btn_rank").attr("class","active");
			$("#btn_school").attr("class","");
			$("#btn_result").attr("class","");
			$("#btn_about").attr("class","");
			$("#btn_home").attr("class","");
		}
		else if(t+1>=SCHOOL){
			$("#btn_contact").attr("class","");
			$("#btn_faq").attr("class","");
			$("#btn_map").attr("class","");
			$("#btn_test").attr("class","");
			$("#btn_rank").attr("class","");
			$("#btn_school").attr("class","active");
			$("#btn_result").attr("class","");
			$("#btn_about").attr("class","");
			$("#btn_home").attr("class","");
		}
		else if(t+1>=FAQ){
			$("#btn_contact").attr("class","");
			$("#btn_faq").attr("class","active");
			$("#btn_map").attr("class","");
			$("#btn_test").attr("class","");
			$("#btn_rank").attr("class","");
			$("#btn_school").attr("class","");
			$("#btn_result").attr("class","");
			$("#btn_about").attr("class","");
			$("#btn_home").attr("class","");
		}
		else if(t+1>=MAP){
			$("#btn_contact").attr("class","");
			$("#btn_faq").attr("class","");
			$("#btn_map").attr("class","active");
			$("#btn_test").attr("class","");
			$("#btn_rank").attr("class","");
			$("#btn_school").attr("class","");
			$("#btn_result").attr("class","");
			$("#btn_about").attr("class","");
			$("#btn_home").attr("class","");
		}
		else if(t+1>=RESULT){
			$("#btn_about").attr("class","");
			$("#btn_faq").attr("class","");
			$("#btn_contact").attr("class","");
			$("#btn_map").attr("class","");
			$("#btn_test").attr("class","");
			$("#btn_rank").attr("class","");
			$("#btn_school").attr("class","");
			$("#btn_result").attr("class","active");
			$("#btn_home").attr("class","");
		}
		else if(t+1>=ABOUT){
			$("#btn_about").attr("class","active");
			$("#btn_faq").attr("class","");
			$("#btn_contact").attr("class","");
			$("#btn_map").attr("class","");
			$("#btn_test").attr("class","");
			$("#btn_rank").attr("class","");
			$("#btn_school").attr("class","");
			$("#btn_result").attr("class","");
			$("#btn_home").attr("class","");
		}
		else{
			$("#btn_home").attr("class","active");
			$("#btn_contact").attr("class","");
			$("#btn_faq").attr("class","");
			$("#btn_map").attr("class","");
			$("#btn_test").attr("class","");
			$("#btn_rank").attr("class","");
			$("#btn_school").attr("class","");
			$("#btn_about").attr("class","");
			$("#btn_result").attr("class","");
		}
	});
});
