<?php
class CreateTableDemo{
	const DB_HOST = 'localhost';
	const DB_NAME = 'classicmodels';
	const DB_USER = 'root';
	const DB_PASSWORD = '';

	private $conn = null;

	/**
	 * Open the database connection
	 */
	public function __construct(){
		// open database connection
		$connectionString = sprintf("mysql:host=%s;dbname=%s",
				CreateTableDemo::DB_HOST,
				CreateTableDemo::DB_NAME);
		try {
			$this->conn = new PDO($connectionString,
					CreateTableDemo::DB_USER,
					CreateTableDemo::DB_PASSWORD);

		} catch (PDOException $pe) {
			die($pe->getMessage());
		}
	}


	/**
	 * create the tasks table
	 * @return boolean returns true on success or false on failure
	 */
	public function createTaskTable() {
		$sql = <<<EOSQL
CREATE TABLE IF NOT EXISTS tasks (
	task_id int(11) NOT NULL AUTO_INCREMENT,
	subject varchar(255) DEFAULT NULL,
	start_date date DEFAULT NULL,
	end_date date DEFAULT NULL,
	description varchar(400) DEFAULT NULL,
	PRIMARY KEY (task_id)
);
EOSQL;
		if($this->conn->exec($sql) !== false)
			return true;
		return false;
	}

	/**
	 * close the database connection
	 */
	public function __destruct() {
		// close the database connection
		$this->conn = null;
	}
}

// create tasks table
$obj = new CreateTableDemo();
if($obj->createTaskTable()){
	echo 'Tasks table created successfully';
}else{
	echo 'Error occured in creating the Tasks table';
}

