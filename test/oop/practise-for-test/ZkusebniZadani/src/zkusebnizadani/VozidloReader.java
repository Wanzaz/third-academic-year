/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zkusebnizadani;

import java.util.HashMap;
import java.util.Scanner;
import zkusebnizadani.readery.AutoReader;
import zkusebnizadani.readery.MotorkaReader;
import zkusebnizadani.readery.Reader;

/**
 *
 * @author majkel
 */
public class VozidloReader {

    private Scanner scanner;
    
    private HashMap<String, Reader> readery;
    
    public VozidloReader(Scanner scanner) {
        this.scanner = scanner;
        readery = new HashMap<String, Reader>();
        readery.put("Motorka", new MotorkaReader());
        readery.put("Auto", new AutoReader());
    }
    
    public Vozidlo ctiVozidlo() {
        String vozidlo = scanner.next("[A-Za-z]+");
        return readery.get(vozidlo).cti(scanner);
    }
    
}
