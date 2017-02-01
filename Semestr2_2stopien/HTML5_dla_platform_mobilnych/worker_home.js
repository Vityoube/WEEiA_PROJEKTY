addEventListener('message',onMessage, false);

function onMessage(evt){
	// var imageProperties=evt.data;
	// console.log("Received message " + imageProperties);
	// var imageHeight=imageProperties[0];
	// var imageWidth=imageProperties[1];
	// console.log("Height: "+imageHeight+" Width: "+imageWidth);
	var calculationProperties=evt.data;
	var radius=calculationProperties[4];
	var left_border_x=calculationProperties[0],right_border_x=calculationProperties[1],
	upper_border_y=calculationProperties[2],bottom_border_y=calculationProperties[3],
	width=calculationProperties[5],height=calculationProperties[6];
	var x=Math.floor(Math.random()*width),y=Math.floor(Math.random()*height);
	while (!(x>=radius && x<=left_border_x-radius && y>=radius && y<=height-radius) &&
			!(x>=radius && x<=width-radius && y>=radius && y<=upper_border_y-radius) &&
			!(x>=right_border_x+radius && x<=width-radius && y>=radius && y<=height-radius) &&
			!(x>=radius && x<=width-radius && y>=bottom_border_y+radius && y<=height-radius)){
				x=Math.floor(Math.random()*width);
				y=Math.floor(Math.random()*height);
			}
	postMessage([x,y,radius]);
}
