window.onload = function() {
	var delayInMilliseconds = 250; //1 second

	function yourFunction() {
		update_light_states();
    	setTimeout(yourFunction, delayInMilliseconds);
	}

	yourFunction();
}


function main_2_to_green() {
	var i;

	var y = document.getElementById("light-1").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 1)";
	}

	y = document.getElementById("light-1").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 0.5)";
	}

	y = document.getElementById("light-2").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 0.5)";
	}

	y = document.getElementById("light-2").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 1)";
	}

	y = document.getElementById("light-3").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 1)";
	}

	y = document.getElementById("light-3").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 0.5)";
	}

	y = document.getElementById("light-4").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 0.5)";
	}

	y = document.getElementById("light-4").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 1)";
	}
}

function second_2_to_green() {
	var i;

	var y = document.getElementById("light-2").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 1)";
	}

	y = document.getElementById("light-2").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 0.5)";
	}

	y = document.getElementById("light-1").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 0.5)";
	}

	y = document.getElementById("light-1").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 1)";
	}

	y = document.getElementById("light-4").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 1)";
	}

	y = document.getElementById("light-4").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 0.5)";
	}

	y = document.getElementById("light-3").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 0.5)";
	}

	y = document.getElementById("light-3").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 1)";
	}
}

function main_3_to_green() {
	var i;

	var y = document.getElementById("light-5").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 1)";
	}

	y = document.getElementById("light-5").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 0.5)";
	}

	y = document.getElementById("light-6").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 0.5)";
	}

	y = document.getElementById("light-6").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 1)";
	}

	y = document.getElementById("light-7").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 1)";
	}

	y = document.getElementById("light-7").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 0.5)";
	}

	y = document.getElementById("light-8").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 0.5)";
	}

	y = document.getElementById("light-8").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 1)";
	}
}

function second_3_to_green() {
	var i;

	var y = document.getElementById("light-6").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 1)";
	}

	y = document.getElementById("light-6").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 0.5)";
	}

	y = document.getElementById("light-5").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 0.5)";
	}

	y = document.getElementById("light-5").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 1)";
	}

	y = document.getElementById("light-8").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 1)";
	}

	y = document.getElementById("light-8").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 0.5)";
	}

	y = document.getElementById("light-7").getElementsByClassName("green-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(0, 255, 0, 0.5)";
	}

	y = document.getElementById("light-7").getElementsByClassName("red-light");
	for (i = 0; i < y.length; i++) {
		y[i].style.backgroundColor = "rgba(255, 0, 0, 1)";
	}
}

function update_light_states() {
	xmlhttp = new XMLHttpRequest();
	xmlhttp.onreadystatechange = function() {
    	if (this.readyState == 4 && this.status == 200) {
    		first_list = this.responseText;
    		// console.log(first_list);
    		states_list = [];
    		for (i = 0; i < first_list.length; i+=4) {
    			id_light = first_list[i];
    			state_light = first_list[i+2];
    			console.log(id_light);
    			console.log(state_light);
    			if (id_light == 2) {
    				if (state_light == 'V') {
    					main_2_to_green();
    				} else {
    					second_2_to_green();
    				}
    			}

    			if (id_light == 3) {
    				if (state_light == 'V') {
    					main_3_to_green();
    				} else {
    					second_3_to_green();
    				}
    			}

    		}
    		
    	}
    };
    xmlhttp.open("GET","../scripts/php/read_txt.php",true);
    xmlhttp.send();
}
