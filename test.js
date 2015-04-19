var bubblesort = require('./build/Release/bubblesort');

console.log(bubblesort.sort([3,1,4,6,2],function(msg){
	console.log("function callback:",msg);
}));