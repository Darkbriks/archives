library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Test_Select is
end Test_Select;

architecture Behavioral of Test_Select is
    component Select_Id_Blake
        Port ( res_id_1 : in STD_LOGIC;
               res_id_2 : in STD_LOGIC;
               selected_id : in STD_LOGIC;
               result : out STD_LOGIC);
    end component;
    
    signal res_id_1: STD_LOGIC:='0';
    signal res_id_2: STD_LOGIC:='0';
    signal selected_id: STD_LOGIC:='0';
    signal result: STD_LOGIC:='0';
    
    constant period:time :=10 ns;
    
begin
    Generate_In: process
    begin
        res_id_1 <= '0'; res_id_2 <= '0'; selected_id <= '0';
        wait for period;
        res_id_1 <= '1'; res_id_2 <= '0'; selected_id <= '0';
        wait for period;
        res_id_1 <= '0'; res_id_2 <= '1'; selected_id <= '0';
        wait for period;
        res_id_1 <= '1'; res_id_2 <= '1'; selected_id <= '0';
        wait for period;
        res_id_1 <= '0'; res_id_2 <= '0'; selected_id <= '1';
        wait for period;
        res_id_1 <= '1'; res_id_2 <= '0'; selected_id <= '1';
        wait for period;
        res_id_1 <= '0'; res_id_2 <= '1'; selected_id <= '1';
        wait for period;
        res_id_1 <= '1'; res_id_2 <= '1'; selected_id <= '1';
        wait for period;
        res_id_1 <= '0'; res_id_2 <= '0'; selected_id <= '0';
        wait;
    end process;

    Test : Select_Id_Blake PORT MAP(res_id_1, res_id_2, selected_id, result);
end Behavioral;