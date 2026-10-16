library IEEE;
use IEEE.STD_LOGIC_1164.ALL;



entity Afficheur_Binaire is
    Port ( sel : in STD_LOGIC;
            a : out STD_LOGIC;
            b : out STD_LOGIC;
            c : out STD_LOGIC;
            d : out STD_LOGIC;
            e : out STD_LOGIC;
            f : out STD_LOGIC;
            g : out STD_LOGIC;
            dp : out STD_LOGIC);
end Afficheur_Binaire;

architecture Behavioral of Afficheur_Binaire is

begin
    a<='1' when sel='1' else '0' when sel='0';
    b<='0';
    c<='0';
    d<='1' when sel='1' else '0' when sel='0';
    e<='1' when sel='1' else '0' when sel='0';
    f<='1' when sel='1' else '0' when sel='0';
    g<='1';
    dp<='1';
end Behavioral;
