/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package farma02.pazourekondrej;

import java.util.Arrays;
import java.util.List;

/**
 *
 * @author ondrejpazourek
 */
public class Farma02PazourekOndrej {

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		List<Animal> animalList = Arrays.asList(
		    new Dog("Andrej"),
			new Bird("Papa"),
			new Cat("Cenek"),
			new Cow("Koval"),
			new Pig("Hans"),
			new Pig("Dzur"),
			new Cow("Komt"),
			new Cat("Vofh"),
			new Cat("Vje"),
			new Dog("Co")
		);
		
		// Display the names of the specific animals in the list
        for (Animal animal : animalList) {
            animal.makeSound();
        }
		
	}
	
}
