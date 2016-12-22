addEventListener('message',onMessage, false);

function onMessage(evt){
	var imageProperties=evt.data;
	console.log("Received message " + imageProperties);
	var imageHeight=imageProperties[0];
	var imageWidth=imageProperties[1];
	console.log("Height: "+imageHeight+" Width: "+imageWidth);
	var radius=Math.floor(Math.random()*200);
	var x=Math.floor(Math.random()*(imageHeight-2*radius));
	var y=Math.floor(Math.random()*(imageWidth-2*radius));
	while(x-radius<0 || y-radius<0 || x+radius>imageWidth || y+radius>imageHeight)
		radius--;
	postMessage([x,y,radius]);
}
