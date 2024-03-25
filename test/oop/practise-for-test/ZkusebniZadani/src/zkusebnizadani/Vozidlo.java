/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zkusebnizadani;

/**
 *
 * @author majkel
 */
public abstract class Vozidlo {
    // Vozidlo ma spotrebu (kolik litru je na 1 kilometr), nadrz (v litrech), 
    // spzku a pocet kol a informaci zda je pojizdne (promenna pojizdne)
    // nebo ne. Ke vsemu existuji gettery,
    // settery ne. Konstruktor neobsahuje pocet kol a pojizdnost, to se nastavi
    // v konstruktoru potomka
	
	protected int spotreba;
	protected int nadrz;
	protected String spz;
	protected int kola;
	protected boolean pojizdne;


	public Vozidlo(int spotreba, int nadrz, String spz, int kola) {
		this.spotreba = spotreba;
		this.nadrz = nadrz;
		this.spz = spz;
		this.kola = kola;
		this.pojizdne = true;
	}
	
	public boolean isPojizdne() {
		return pojizdne;
	}
	
	public int getSpotreba() {
		return spotreba;
	}

	public int getNadrz() {
		return nadrz;
	}

	public String getSpz() {
		return spz;
	}

	public int getKola() {
		return kola;
	}
    
    
    // Metoda "ujed" prijme pocet kilometru a podle spotreby odecte z nadrze
    // Kdyz vozidlo jede tak se vypise jeho SPZ spolu se zvukem ktery vydava
    // Pokud vozidlo kixne (vzdalenost ma vetsi spotrebu nez je v nadrzi) tak
    // se nastavi pojizdne na false 
    
	public void ujed(int pocetKilometru) {
		System.out.print(this.spz + ": ");
		vydejZvuk();
		int benzin = this.spotreba * pocetKilometru;
		
		if (benzin > this.nadrz) {
			this.pojizdne = false;
			this.nadrz = 0;
			return;
		}

		this.nadrz -= benzin;
	}

	
    // Metoda vydejZvuk vytiskne zvuk vozidla (nic lepsiho me nenapadlo) a bude 
    // prekryvana kazdym potomkem
	public abstract void vydejZvuk();
	
	
}
