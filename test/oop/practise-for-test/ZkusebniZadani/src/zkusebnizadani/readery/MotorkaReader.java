/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zkusebnizadani.readery;

import java.util.Scanner;
import zkusebnizadani.Motorka;
import zkusebnizadani.Vozidlo;

/**
 *
 * @author misa
 */
public class MotorkaReader implements Reader {

    @Override
    public Vozidlo cti(Scanner scanner) {
        return new Motorka(scanner.nextInt(), scanner.nextInt(), scanner.next());
    }
    
}
