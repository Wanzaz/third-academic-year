/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zkusebnizadani;

/**
 *
 * @author majkel
 */
public class Auto extends Vozidlo {
	protected String zvuk;
	
	
	
	// auto dela vrrrrrr a ma 4 kola
	public Auto(int spotreba, int nadrz, String spz) {
		super(spotreba, nadrz, spz, 4);
		this.zvuk = "vrrrr";
	}

	@Override
	public void vydejZvuk() {
		System.out.println(this.zvuk);
	}
	
}
