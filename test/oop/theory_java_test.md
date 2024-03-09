# A
### 1. Vysvetli pojmy stav a identita objektu a vysvetli rozdily mezi nimi. (4 b)

#### Objekt
- Má svou identitu.
- Zabírá konkrétní paměťovou buňku.
- Má svůj stav.
- Aktuální hodnoty datových položek objektu.
- Dva objekty mohou být shodné, tj. mít totožný stav, ale přesto mohou mít dvě nezávislé identity.
- Totožnost identit
- Na tentýž objekt může odkazovat více proměnných!
- V Javě jsou objektové proměnné reference (tj. ukazatele)!

```c
// ukazuje na dva jine objekty
Pes tvujPes = new Pes("Azor");
Pes mujPes = new Pes("Alík");

// ukazuje na stejny objekt
Pes tvujPes = new Pes("Alík");
Pes mujPes = tvujPes;
mujPes.prejmenuj("Azor");
```

### 2. Vytvor rozhrani Hra predepisující metodu tah. Vy- tvor alespon dve tridy s tímto rozhraním (pri tahu tiskni rozeznately text). Vytvor 1 seznam (pouzij typ ArrayList<>) alespon 4 her téchto typü. Ve vsech hrách proved 1 tah. Na svém resení vysvetli, jak funguje polymorfismus. (6 b)
```c
public interface Hra {
    public void tah();
}

public class Sachy implements Hra {
    @Override
    public void tah() { System.out.println("Sachy tahnou"); };
}

public class Schovka implements Hra {
    @Override
    public void tah() { System.out.println("Schovka tahne"); };
}

// prace se seznamem
var seznamHer = new ArrayList<Hra>(Schovka );

seznamHer.add(new Sachy());
seznamHer.add(new Schovka());
seznamHer.add(new Schovka());
seznamHer.add(new Sachy());

// Provádění tahu ve všech hrách
for (Hra hra : seznamHer) {
    hra.tah();
}

Polymorfismus umožňuje používat objekty různých tříd, které implementují stejné rozhraní nebo jsou odvozeny od společného předka, a to bez znalosti konkrétní třídy, což zjednodušuje a zobecňuje práci s různými typy objektů.

```

# B
### 1. Popis a vysvetli pojem zapouzdient. K demu je to dabré? (4 b)
#### Zapouzdření

- Sloučení vlastností (atributů) a činností (metod), které logicky patří k sobě, do jediného celku.
- Práva přístupu
- Specifikována pro každou položku.
- Veřejné (public) položky tvoří veřejné rozhraní.
- Chráněné (protected) + veřejné tvoří rozhraní pro
potomky.
- Ochrana dat
- Proměnné atributy nedělat veřejné!
- Vždy alespoň chráněné (protected), nebo privátní (private).
- Přátelské atributy – jen u pomocných anebo vnořených tříd.
- Veřejné rozhraní by měly tvořit jen metody.
- Dovolují dělat dodatečné kontroly.
- Cílem je omezit uživatelům objektu možnost poškození
datových struktur.

#### 2. Pouzij tridu Scanner a metodu nextInt pro nacteni presne 10 celych cisel ze standardniho vstupu do seznamu typu ArrayList<T>. Potom seznam vytiskni na standarndni vystup. Osetruj pri tom vyjmkou InputMismatchException. Na konci musi byt vstupni skener uzavren. Vysvetli na tomto prikladu., co jsou to vyjimky a jak funguji.
```java
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            List<Integer> seznamCisel = nacistDesetCelychCisel(scanner);

            System.out.println("Seznam celých čísel:");
            for (Integer cislo : seznamCisel) {
                System.out.println(cislo);
            }

        } catch (InputMismatchException e) {
            System.out.println("Chyba při čtení vstupu: " + e.getMessage());
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }
    }

    private static List<Integer> nacistDesetCelychCisel(Scanner scanner) throws InputMismatchException {
        List<Integer> seznamCisel = new ArrayList<>();

        System.out.println("Zadejte 10 celých čísel:");

        for (int i = 0; i < 10; i++) {
            seznamCisel.add(scanner.nextInt());
        }

        return seznamCisel;
    }
}
```

# C
### 1. Co je prekryti a co je pretizeni
#### Přetěžování metod (overloading)

- Ve třídě lze mít více metod stejného jména.
- Nestačí pouze přejmenovat parametry.
- Musí se lišit počtem nebo typy parametrů.
- Zvyšuje to přehlednost.
- Není potřeba vymýšlet nové názvy metod, které dělají totéž, jen s jiným typem parametrů.
- Anglicky: method overloading

#### Překrývání metod (overriding)

- Potomek může přepsat metodu předka.
- Metoda má stejnou hlavičku, ale chová se jinak.
- Využití – viz polymorfismus.
- Anglicky: method overriding
- Tip: Před metodou se používá (nepovinná) anotace
- @Override. Umožňuje lepší kontrolu překladačem.

### 2. Udelat list (ArrayList) s aspon 4 figurkama (Pesak a Jezdec) pomoci polymorfyzmu vsem v poly dej prikaz k provedeni tahu
```c
import java.util.ArrayList;
import java.util.List;

// Rozhraní pro figurky
interface Figurka {
    void provedTah();
}

// Implementace figurky Pesak
class Pesak implements Figurka {
    @Override
    public void provedTah() {
        System.out.println("Pesak provedl tah.");
    }
}

// Implementace figurky Jezdec
class Jezdec implements Figurka {
    @Override
    public void provedTah() {
        System.out.println("Jezdec provedl tah.");
    }
}

public class Main {
    public static void main(String[] args) {
        // Vytvoření seznamu figur
        List<Figurka> seznamFigur = new ArrayList<>();

        // Přidání figur do seznamu
        seznamFigur.add(new Pesak());
        seznamFigur.add(new Jezdec());
        seznamFigur.add(new Pesak());
        seznamFigur.add(new Jezdec());

        // Provedení tahu u všech figur pomocí polymorfismu
        for (Figurka figurka : seznamFigur) {
            figurka.provedTah();
        }
    }
}
```


# D
### 1. Vysvetli a popis princip tabulky virtualnich me-tod. Kdy, k cemu a jak se pouzívá? (4 b)
#### Tabulka virtuálních metod

- Dynamicky vyrobený objekt si při vzniku alokuje také tabulku virtuálních metod.
- Má v ní (ukazatele na) virtuální metody své a svých předků.
- Jsou seřazeny směrem od implementací v potomcích k implementacím v předcích.
- Virtuální metoda se při volání vyhledá v tabulce virtuálních metod objektu.
- Proto Zvire b zavolá metodu ozviSe, která vypíše „Haf!“, ne „Mmm?“.
- Pozdní vazba
- Virtuální metoda se před zavoláním vyhledává v tabulce virtuálních metod.
- Cena za polymorfismus – pomalejší volání.
- Časná vazba
- Nevirtuální metody se volají přímo.
- Efektivnější, ale nejde je překrývat.
- V Javě – finální a privátní metody.

### 2. V souboru data. txt je ulozena rada desetinných císel typu double. Nati ji do seznamu typu Array - List<T> a vytiskni jej na standardní výstup. Pouzij InputStream a Scanner (metody hasNextDouble, nextDouble). Osetri vyjimky FileNotFoundExcep- tion a InputMismatchException. Vstup musí být na konci uzavren. Vysvetli na tomto príkladu od- chyt vyjimek se zdrojem. (6 b)
```c
// importovani si pomatovat nemusis
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;



public class Main {
    public static void main(String[] args) {
        try {
            List<Double> seznamCisel = nacistCislaZeSouboru("data.txt");
            tiskniSeznam(seznamCisel);
        } catch (FileNotFoundException e) {
            System.out.println("Soubor nenalezen: " + e.getMessage());
        } catch (InputMismatchException e) {
            System.out.println("Chyba při čtení dat: " + e.getMessage());
        }
    }

    private static List<Double> nacistCislaZeSouboru(String nazevSouboru) throws FileNotFoundException, InputMismatchException {
        List<Double> seznamCisel = new ArrayList<>();

        try (Scanner scanner = new Scanner(new FileInputStream(new File(nazevSouboru)))) {
            while (scanner.hasNextDouble()) {
                seznamCisel.add(scanner.nextDouble());
            }
        }

        return seznamCisel;
    }

    private static void tiskniSeznam(List<Double> seznam) {
        System.out.println("Seznam čísel:");
        for (Double cislo : seznam) {
            System.out.println(cislo);
        }
    }
}
```
