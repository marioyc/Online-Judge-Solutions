var test = function(){
	OS.exec('reqant ' + OS.usr + ' ' + OS.pwd, function(stdout) {
	    //print((stdout || '') + '\n');
	    //term.q('.bottom').className = 'bottom';
	    //input.readOnly = false;
	    //scroll();
	    //input.focus();

	    lines = document.q('pre').innerHTML.split('\n');
	    var antena = lines[lines.length - 2];

	    OS.exec('photocmd ' + antena, function(stdout){
	    	lines = document.q('pre').innerHTML.split('\n');
	    	words = lines[lines.length - 2].split(' ');
	    	filename = words[words.length - 1];

	    	OS.exec('photoview ' + filename, function(stdout){

	    	});
	    });
	});
};