/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package farma02.pazourekondrej;

/**
 *
 * @author ondrejpazourek
 */
public class Animal {

	protected String name;
	protected int numberOfLegs;
	protected String sound;

	public Animal(String name, int numberOfLegs, String sound) {
		this.name = name;
		this.numberOfLegs = numberOfLegs;
		this.sound = sound;
	}

	
	public void makeSound() { }
	
}
