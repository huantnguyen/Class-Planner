

function testFunction(clicked_id) {
  let test = document.getElementById(clicked_id).textContent;
  document.getElementById(clicked_id).parentElement.previousElementSibling.innerHTML=test;
}

function nextPage() {
	document.getElementById('secondPage').style.display='none';
	document.getElementById('thirdPage').style.display='block';
}