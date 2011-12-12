/* Slider Class - www.anthonymattox.com */
/* adapted by - www.guilhermemartins.net */

class sliderH {
  int x, y, w, h;
  float p, fp; // fp : final pos - the pos we want to know
  boolean slide;
  color c, cb;
  float minval, maxval;
  int result;
  boolean dragging;
  /*
  
   x : x
   y : y
   s : size
   col : color
   start : start value
   _min : min value to be mapped
   _max : max value to be mapped
   _interp : interpolate true or false
   _filtro : interp filter
   
   */

  sliderH (int _x, int _y, int _w, int _h, color col, float _start, float _min, float _max) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    slide = true;
    c = col;
    minval = _min;
    maxval = _max;
    p = map(_start, minval, maxval, x, x+w);
    fp = map(p, x, x+w, minval, maxval);
    cb = color(red(c),green(c),blue(c));
    dragging = false;
  }

  void render() {

    noStroke();
    fill(200, 50);
    rect(x, y, w+5, h+1);

    noStroke();
    fill(cb);
    rect(p, y, 2, h);

    result = (int)fp;
    
    fill(180);
    text(result, x, y+h-1);
    dragging = false;
    if (slide=true && mousePressed==true && mouseY>y && mouseY<y+h){
      dragging = true;
      if ((mouseX<=x+w) && (mouseX>=x)) {

          p = mouseX;
          fp = map(p, x, x+w, minval, maxval);
        
        if (p<0) {
          p=0;
        } 
        else if (p>x+w) {
          p=x+w;
        }
      }
    }
  }
  
  
}


