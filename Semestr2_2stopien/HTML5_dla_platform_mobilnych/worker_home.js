addEventListener('message',onMessage, false);

function onMessage(evt){
	console.log("Recieved message " + evt.data);
	var mainCtx=evt.data;
	var radius=Math.floor()*200;
	var x=Math.floor(Math.random()*(mainCtx.width-radius);
	var y=Math.floor(Math.random()*(mainCtx.height-radius);
	postMessage([x,y,radius]);
}
