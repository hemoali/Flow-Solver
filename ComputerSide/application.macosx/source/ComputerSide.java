import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class ComputerSide extends PApplet {



Serial port;

String lines[];

public void setup() {

    //Read From File 
    port = new Serial(this, Serial.list()[5], 9600);

    //Reading INstructions from the user
    lines = loadStrings("/Users/ibrahimradwan/Development/puzzlesolver/final_package_flow_solver/Path.txt");
    //Serial communication Protocol

    port.write(10);
    delay(600);
    port.write(10);
    delay(600);
}

int x = 1;
int index = 0;

public void draw() {
    //We are now applying the instructions
    if (index < lines.length) {
        String path = lines[index];
        if (path.equals("")) {} else {
            for (int i = 0; i < path.length(); i++) {
                port.write(path.charAt(i));
                delay(2000);
            }
        }
        index = index + 1;
    }
    port.write('=');
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "ComputerSide" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
