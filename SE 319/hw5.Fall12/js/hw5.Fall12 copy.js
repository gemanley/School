$(function() {
	$(".menuitems").hide();
	alert('Hello! I am tlund');

	$("#dmenu li:has(.menuitems)").click(function() {
		$(this).children(".menuitems").slideToggle();
	});

	$(".menuitems").children("li").click(function() {
		$.get("aux/" + $(this).text() + ".html", function(data) {
			$("#content").html(data);
		}, "text");
		return false;
	});
});