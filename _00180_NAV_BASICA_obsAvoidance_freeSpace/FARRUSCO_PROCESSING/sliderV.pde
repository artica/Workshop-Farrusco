/* Slider Class - www.anthonymattox.com */
/* adapted by - www.guilhermemartins.net */


/* Slider Class - www.anthonymattox.com */
/* adapted by - www.guilhermemartins.net */

class sliderV {
  int x, y, w, h;
  float p, pp;
  //float filtro = 0.1;
  boolean slide;
  color c, cb;
  float filtro;
  int result;
  int minval, maxval;
  boolean dragging;
 
//  _x : xpos
//  _y : ypos
//  _w : width
//  _h : height
//  _col : color
//  _start : start position

 
  
  
  sliderV (int _x, int _y, int _w, int _h, color _col, float _start, int _min, int _max) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    p = _start;
    slide = true;
    c = _col;
    cb = color(red(c),green(c),blue(c));
    minval = _min;
    maxval = _max;
    dragging = false;
  }

  void render() {

    noStroke();
    fill(200, 50);
    rect(x, y, w, h);

    noStroke();
    fill(cb);
    rect(x, h-p+y, w, 14);
    
//    fill(255);
//    text(round(p), x+(w/2)-13, y-6);

    result = (int)map(round(p), 0, h, minval, maxval);
    
    fill(0);
    text(result, x+1, h-p+y+10);
    dragging = false;
    if (slide=true && mousePressed==true && mouseX<x+25 && mouseX>x){
      
      if ((mouseY<=y+h) && (mouseY>=y)) {
        dragging = true;
        p = h-(mouseY-y); //p + (h-(mouseY-y));
      
        if (p<0) {
          p=0;
        } 
        else if (p>h) {
          p=h;
        }
      }
    }
  }
  
  
  
  void render(int sliderPos) {
    
    //sliderPos = _sliderPos;

    noStroke();
    fill(200, 50);
    rect(x-1, y-4, w, h+10);

    noStroke();
    fill(cb);
    rect(x, h-p+y-5, w, 13);
    fill(c);
    rect(x+2, h-p+y-5, w-5, 13);
    fill(0);
    text(round(p), x+2, h-p+y+6);
    if(result!= sliderPos)
      p = map (sliderPos, minval, maxval,0,h);// + (h-(sliderPos-y));
  
  }
}


/*
class sliderV {
  int x, y, w, h;
  float p, fp; // fp : final pos - the pos we want to know
  //float filtro = 0.1;
  boolean slide;
  color c, cb;
  float filtro;
  int minval, maxval;
  int result;
  
  // _x : xpos
  // _y : ypos
  // _w : width
  // _h : height
  // _col : color
  //_start : start position
  
  
  
  
  sliderV (int _x, int _y, int _w, int _h, color _col, float _start, int _min, int _max) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    p = _start;
    slide = true;
    c = _col;
    cb = color(red(c),green(c),blue(c),150);
    minval = _min;
    maxval = _max;
    
    fp = map(p, x, x+w, minval, maxval);
  }

  void render() {

    noStroke();
    fill(200, 50);
    rect(x-1, y-4, w, h+10);

    noStroke();    
    fill(cb);
    rect(x, h-p+y-5, w-1, 13);
    
    result = (int)map(round(p), 0, h, minval, maxval);
    
    fill(0);
    text(result, x+1, h-p+y+6);

    if (slide=true && mousePressed==true && mouseX<x+w && mouseX>x){
      if ((mouseY<=y+h+10) && (mouseY>=y-5)) {
        
        p = h-(mouseY-y);
        
        if (p<0) {
          p=0;
        } 
        else if (p>h) {
          p=h;
        }
      }
    }
  }
}
*/




