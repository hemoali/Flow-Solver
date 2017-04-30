import processing.serial.*;

Serial port;

String lines[];

void setup() {

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

void draw() {
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