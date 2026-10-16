-- insertion des bibliothèques utilisées
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- declaration de l'interface du module : entité
-- definition des E/S
entity AfficheurBinaire is
    Port ( sel : in STD_LOGIC;
           a : out STD_LOGIC;
           b : out STD_LOGIC;
           c : out STD_LOGIC;
           d : out STD_LOGIC;
           e : out STD_LOGIC;
           f : out STD_LOGIC;
           g : out STD_LOGIC;
           dp : out STD_LOGIC);
end AfficheurBinaire;

-- declaration d'un comportement associé à l'entité : architecture
architecture Behavioral of AfficheurBinaire is
begin
--plusieurs instructions concurentielles independantes
-- une instruction se termine toujours pas un point virgule
--when/else permet un assignement conditionnel d'un signal 
--     remplace l'écriture if then conditionné à un process sequentiel.
	a<='1' when sel='1' else '0' when sel='0';
	b<='0';
	c<='0';
	d<='1' when sel='1' else '0' when sel='0';
	e<='1' when sel='1' else '0' when sel='0';
	f<='1' when sel='1' else '0' when sel='0';
	g<='1'; -- barre milieu
	dp<='1';-- le point
end Behavioral;
