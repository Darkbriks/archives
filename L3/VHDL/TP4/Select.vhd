library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Select_Id_Blake is
    Port ( res_id_1 : in STD_LOGIC;
           res_id_2 : in STD_LOGIC;
           selected_id : in STD_LOGIC;
           result : out STD_LOGIC);
end Select_Id_Blake;

architecture Behavioral of Select_Id_Blake is
begin
    result<= res_id_1 when selected_id = '0' else res_id_2;
end Behavioral;