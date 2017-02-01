addEventListener('message',onMessage, false);

function onMessage(evt){
	var imageProperties=evt.data;
	console.log("Received message " + imageProperties);
	var imageHeight=imageProperties[0];
	var imageWidth=imageProperties[1];
	console.log("Height: "+imageHeight+" Width: "+imageWidth);
	var radius=50;
	var x=Math.floor(Math.random()*(imageHeight-2*radius));
	var y;
	while (x>radius/2 && x<imageHeight/4)
		x--;
	while (x<radius/2)
		x++;
	while (x<3*imageWidth/4 -radius/2)
		x++;
	while (x>imageWidth-radius/2)
		x--;
	if (x<imageWidth/4 || x>3*imageWidth/4)
		y=Math.floor(Math.random()*(imageHeight));
	else if (x>=imageWidth/4 || x<=3*imageWidth/4)
		y=Math.floor(Math.random()*imageHeight/4);
	while(y<radius/2)
		y++;
	while(y>imageHeight-radius/2)
		y--;
	// while(x-radius<0 || y-radius<0 || x+radius>imageWidth || y+radius>imageHeight)
	// 	radius--;
	postMessage([x,y,radius]);
}
