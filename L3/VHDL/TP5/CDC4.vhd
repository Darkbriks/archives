library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity CDC4 is
    Port ( e1 : in STD_LOGIC_VECTOR (3 downto 0);
           bloc_afficheur : out STD_LOGIC_VECTOR (7 downto 0);
           led : out STD_LOGIC_VECTOR (3 downto 0);
           an : out STD_LOGIC_VECTOR (3 downto 0));
end CDC4;

architecture Behavioral of CDC4 is

    component AfficheurRelatif
        Port ( input : in STD_LOGIC_VECTOR (3 downto 0);
               negate : in STD_LOGIC;
               output : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    component ComplementA2
        Port ( input : in STD_LOGIC_VECTOR (3 downto 0);
               output : out STD_LOGIC_VECTOR (3 downto 0));
    end component;
    
    signal negate : STD_LOGIC;
    signal complement_a_2_e1 : STD_LOGIC_VECTOR (3 downto 0);
    signal signal_to_display : STD_LOGIC_VECTOR (3 downto 0);
    
begin
    an <= "1110";
    led <= e1;
    negate <= e1(3);
    signal_to_display <= e1 when e1(3) = '0' else complement_a_2_e1;
    Mapping_ComplementA2 : ComplementA2 PORT MAP (e1, complement_a_2_e1);
    Mapping_Afficheur : AfficheurRelatif PORT MAP (signal_to_display, negate, bloc_afficheur);
end Behavioral;
