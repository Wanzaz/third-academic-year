/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package farma02.pazourekondrej;

/**
 *
 * @author ondrejpazourek
 */
public class Cow extends Animal {
	protected String race;
	protected int age;

	public Cow(String name, String race, int age) {
		super(name, 2, "Buu");
		this.age = age;
		this.race = race;
	}
	
	public Cow(String name) {
		super(name, 2, "Buu");
		this.age = 0;
		this.race = "NoRace";
	}
	
	@Override
	public void makeSound() {
		System.out.println(this.sound);
	}
}