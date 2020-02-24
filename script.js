function testFunction(clicked_id) {
  let test = document.getElementById(clicked_id).textContent;
  document.getElementById(clicked_id).parentElement.previousElementSibling.innerHTML=test;
}

function nextPage() {
	document.getElementById('secondPage').style.display='none';
	document.getElementById('fourthPage').style.display='block';
}


// READ FILE
function readFile(file)
{
    var f = new XMLHttpRequest();
    f.open("GET", file, false);
    f.onreadystatechange = function ()
    {
        if(f.readyState === 4)
        {
            if(f.status === 200 || f.status == 0)
            {
                var res= f.responseText;
                var splitted = res.split("\n");  
                //console.log(splitted); //to see if contents are read
                //console.log(typeof splitted[0]);
            }
        }
    }
    f.send(null);
}

readFile('statsprereq.txt');

function addOptions()
{
	let data;
  fetch("https://f9f9332c.ngrok.io/taken?course_taken=STATS%2020").then(response => response.json())
  .then(response => {
    var preReq = response.data;
    //console.log(preReq);
    for(i=0; i<preReq.length; i++)
    {
      var taken = preReq[i];
      $('#prereq').append(`<option class="choices" value="${taken}">${taken}</option>`);
      //console.log(taken);
    }
  })

}

function nextPage2() {
	document.getElementById('fourthPage').style.display='none';
	document.getElementById('thirdPage').style.display='block';
}


//Add satisfied Prereq
var g = document.getElementById('prereq');
var c = g.children[0];
for (var i = 0, len = g.children.length; i < len; i++)
{
    //console.log(g.children);
    (function(index){
        g.children[i].onclick = function(){
          alert(index)  ;
        }    
    })(i);

}

/*function transferClass() {
  $('#prereq').on('click', '#transfer', function (event) {
    event.preventDefault();
    let choice = $('option:checked').val();
    console.log(choice);
  });
}

transferClass();*/
function getSchedule()
{
	let data;
  fetch("https://f9f9332c.ngrok.io/schedule").then(response => response.json())
  .then(response => {
    let preReq = response.data;
    console.log(preReq);
  for(i=0; i<3; i++)
    {
      let taken = preReq[0][i];
      $('#recc1').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  for(i=0; i<3; i++)
    {
      let taken = preReq[1][i];
      $('#recc2').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  for(i=0; i<4; i++)
    {
      let taken = preReq[2][i];
      $('#recc3').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  for(i=0; i<4; i++)
    {
      let taken = preReq[3][i];
      $('#recc4').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  for(i=0; i<4; i++)
    {
      let taken = preReq[4][i];
      $('#recc5').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  for(i=0; i<4; i++)
    {
      let taken = preReq[4][i];
      $('#recc5').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  for(i=0; i<4; i++)
    {
      let taken = preReq[5][i];
      $('#recc6').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  for(i=0; i<4; i++)
    {
      let taken = preReq[6][i];
      $('#recc7').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  for(i=0; i<4; i++)
    {
      let taken = preReq[7][i];
      $('#recc8').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  for(i=0; i<4; i++)
    {
      let taken = preReq[8][i];
      $('#recc9').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  for(i=0; i<4; i++)
    {
      let taken = preReq[9][i];
      $('#recc10').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  for(i=0; i<4; i++)
    {
      let taken = preReq[10][i];
      $('#recc11').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  for(i=0; i<4; i++)
    {
      let taken = preReq[11][i];
      $('#recc12').append(`<option class="choices" value="${taken}">${taken}</option>`);
      console.log(taken);
    }
  })
}

function random(){

  $('#recc1').append(`<option class="choices" value="STATS 100A">STATS 100A</option>`);
}

function random2(){

  $('#recc2').append(`<option class="choices" value="CHEM 10 100A">CHEM 10</option>`);
}

