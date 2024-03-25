/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zkusebnizadani;

/**
 *
 * @author majkel
 */
public class Motorka extends Vozidlo {
	protected String zvuk;
	
	
	
    // motorka dela mrrrr a ma 2 kola
	public Motorka(int spotreba, int nadrz, String spz) {
		super(spotreba, nadrz, spz, 2);
		this.zvuk = "mrrr";
	}


	@Override
	public void vydejZvuk() {
		System.out.println(this.zvuk);
	}
	
	
}
