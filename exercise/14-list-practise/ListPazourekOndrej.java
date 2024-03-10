/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package listpazourekondrej;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

/**
 *
 * @author ondrejpazourek
 */
public class ListPazourekOndrej {
	
	public static void lists01() { 
		var seznam = new ArrayList<Double>(); // mohl by být i LinkedList<Double>
		/**- var - nové klíčové slovo - Vezme si typ pro deklaraci proměnné z konstruktoru na pravé straně.
		- <Typ> - použití generického typu - Typ se dosazuje až při výrobě proměnné, ne při programování samotné třídy (zde ArrayList). To   dovoluje vytvářet zobecněné kolekce (seznamy, stromy apod.) namísto nutnosti programovat vše znovu (bez toho by byly potřeba extra   seznamy nad typy Integer, Double, Zvire, ...).
		- () - Kulaté závorky jsou tu proto, že se zde volá konstruktor bez parametrů. **/

		// Přidání prvku
		seznam.add(2.5);

		// Indexování prvku
		double prvek = seznam.get(0); // parametrem je index -- pořadové číslo

		// Výpis seznamu
		for (Double cislo : seznam) { // Projde všechny prvky seznamu. Double je třída zastřešující double.
			System.out.println(cislo);
		}
	}
	
	public static void lists02() {
		ArrayList<Double> seznam = new ArrayList<>(); // mohl by být i LinkedList<Double>

		// Odstranění prvku ze seznamu
		// seznam.remove() // -- je několik variant

		// Odstranění prvků při průchodu iterátorem
		// - Nejde v obyčejném cyklu for ani while, protože by se takový cyklus pokazil a skončil chybou.
		// - Musí se použít průchod přes iterátor. Iterátory jsou speciální objekty, které slouží k procházení kolekcí.
		// - Metoda remove se volá nad iterátorem, ne nad seznamem!
		for (int i = 0; i < 4; i++) {
            seznam.add(4.0);
			seznam.add(4.5);
        }
		
		System.out.println(seznam);

		for (Iterator<Double> iterator = seznam.iterator(); iterator.hasNext(); ) {
			Double next = iterator.next();
			if (wantToRemove(next))
			iterator.remove(); // odstranění prvku next, ale pomocí iterátoru!
		}
		for (Double cislo : seznam) {
			System.out.println(cislo);
		}
	}
	
	public static void lists03() {
		var seznam = new ArrayList<Double>();
		// Funkcionální programování (s anonymními funkcemi)
		// - Dají se použít i metody s tzv lambda funkcí (anonymní funkcí, která se zapíše přímo do argumentu funkce).
		
		for (int i = 0; i < 4; i++) {
            seznam.add(4.0);
			seznam.add(5.5);
        }
		// Odstranění všech prvků splňujících zadanou podmínku
		seznam.removeIf(n -> (n > 5.0));
		// - n -> (n > 5.5) je anonymní lambda funkce s tímto významem:
		// - Metoda removeIf ze seznamu odstraní všechny prvky, nad kterými zadaná lambda funkce vrátí true.
		// - viz https://www.geeksforgeeks.org/arraylist-removeif-method-in-java/
		// Vykonání akce nad všemi prvky seznamu
		seznam.forEach((n) -> System.out.println(n));
		// - viz https://www.geeksforgeeks.org/arraylist-foreach-method-in-java/
	}
	
	boolean funkce(double n) { return n > 5.5; }


	public static void main(String[] args) {
		System.out.println("-------");
		lists01();
		System.out.println("-------");
		lists02();
		System.out.println("-------");
		lists03();
		System.out.println("-------");
		
	}

	private static boolean wantToRemove(Double next) {
		return next == 4;
	}

	
	
}
