--TEST--
Check basic Ardillo App instantiation
--SKIPIF--
<?php
if (!extension_loaded('ardillo')) {
	echo 'skip';
}
?>
--FILE--
<?php
class TestTask extends Ardillo\Task
{
    public function onExecute(): void
    {
        echo 'OK';
        Ardillo\App::get()->stop();
    }
}

$app = new Ardillo\App();
$app->scheduleTask(new TestTask, 0);
$app->run();
?>
--EXPECT--
OK
