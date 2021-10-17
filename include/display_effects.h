void triangles(U8G2 display)
{
  int x1, y1, x2, y2 = 0;
  int disp_width;
  disp_width = display.getDisplayWidth();
  int disp_height;
  disp_height = display.getDisplayHeight();

    display.clear();
    for (x1=0; x1<disp_width; x1+=5)
    {
    y1 = x1*disp_height/disp_width;
    x2 = disp_width - x1;
    y2 = disp_height - y1;
    display.drawLine(x1,y2,x2,y2);
    display.sendBuffer();
    }
  delay(1000);
  display.clear();

}

void spin(U8G2 display)
{
int x1, y1, x2, y2 = 0;
  int disp_width;
  disp_width = display.getDisplayWidth();
  int disp_height;
  disp_height = display.getDisplayHeight();
  for (y1 = 0; y1 <= disp_height; y1+=5)
    y2 = disp_height - y1;
    for (x1 = 0; x1 <= disp_width; x1+=5)
      {
        x2 = disp_width - x1;
        display.drawLine(x1,y1,x2,y2);
        display.sendBuffer();
      }
  delay(800);
}