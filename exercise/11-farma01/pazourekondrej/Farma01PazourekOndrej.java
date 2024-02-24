/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package farma01.pazourekondrej;

/**
 *
 * @author ondrejpazourek
 */
public class Farma01PazourekOndrej {

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		Dog dog = new Dog("Alik", "vlcak", 2);
		Bird bird = new Bird("Julca", "andulka", 1);
		
		System.out.println(dog.numberOfLegs + " " + dog.name + " " + dog.race + " ");
		System.out.println(bird.numberOfLegs + " " + bird.name + " " + bird.race + " ");
		
		dog.makeSound();
		bird.makeSound();
	}
	
}
