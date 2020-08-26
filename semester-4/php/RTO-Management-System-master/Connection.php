<?php

    class Connection
    {
        function getNewConnection()
        {
            $db = new mysqli("localhost", "root", "", "rto");
            if ($db->connect_error) {
                die("Connection failed: " . $db->connect_error);
            } 
            return $db;
        }
    }

?>