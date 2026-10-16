library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity CDC5 is
    Port ( a : in STD_LOGIC_VECTOR (3 downto 0);
           b : in STD_LOGIC_VECTOR (3 downto 0);
           led : out STD_LOGIC_VECTOR (7 downto 0);
           an : out STD_LOGIC_VECTOR (3 downto 0);
           seg : out STD_LOGIC_VECTOR (7 downto 0));
end CDC5;

architecture Behavioral of CDC5 is
    component Soustraction is
        Port ( a : in STD_LOGIC_VECTOR (3 downto 0);
               b : in STD_LOGIC_VECTOR (3 downto 0);
               output : out STD_LOGIC_VECTOR (3 downto 0));
    end component;
    
    component Concatenation is
        Port ( a : in STD_LOGIC_VECTOR (3 downto 0);
               b : in STD_LOGIC_VECTOR (3 downto 0);
               led : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    component CDC4 is
        Port ( e1 : in STD_LOGIC_VECTOR (3 downto 0);
               bloc_afficheur : out STD_LOGIC_VECTOR (7 downto 0);
               an : out STD_LOGIC_VECTOR (3 downto 0));
    end component;
    
    signal result_ca2 : std_logic_vector (3 downto 0);
begin    
    Map_Led : Concatenation PORT MAP (a, b, led);
    Map_Soustraction : Soustraction PORT MAP (a, b, result_ca2);
    Map_CDC4 : CDC4 PORT MAP (result_ca2, seg, an);

end Behavioral;
