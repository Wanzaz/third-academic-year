/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zkusebnizadani.readery;

import java.util.Scanner;
import zkusebnizadani.Auto;
import zkusebnizadani.Vozidlo;

/**
 *
 * @author misa
 */
public class AutoReader implements Reader {

    @Override
    public Vozidlo cti(Scanner scanner) {
        return new Auto(scanner.nextInt(), scanner.nextInt(), scanner.next());
    }
}
