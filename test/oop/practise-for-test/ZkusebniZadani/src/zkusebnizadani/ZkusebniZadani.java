/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package zkusebnizadani;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.function.Predicate;

/**
 *
 * @author majkel
 */
public class ZkusebniZadani {

    /**
     * @param args the command line arguments
	 * @throws java.io.FileNotFoundException
     */
    public static void main(String[] args) throws FileNotFoundException {
        // otevri soubor a nacti do pole vsechna auta
		var seznam = new LinkedList<Vozidlo>();
		try (Scanner sc = new Scanner(new FileReader("data.txt"))) {
			var reader = new VozidloReader(sc);
			while (sc.hasNext()) {
				seznam.add(reader.ctiVozidlo());
			}
			
			vypisPrezivsichVozidel(seznam);
			
		} catch (FileNotFoundException o_o) {
			System.out.println("je to v pici");
		}
        // 5x nech kazde vozidlo ujet nahodny pocet kilometru (jak se dela 
        // nahoda si najdi na internetu)
        // Pote vypis vsechna prezivsi vozidla, pouzij na to metodu nize
    }
   
    public static void vypisPrezivsichVozidel(List<Vozidlo> seznam) {
		seznam.removeIf((i) -> !i.isPojizdne());
		
        for (int i = 0; i < 1; i++) {
				var random = new Random();
				seznam.forEach(
					(vuz) -> {
						vuz.ujed(random.nextInt(100));
						
					}
				);
			}
    }    
}
