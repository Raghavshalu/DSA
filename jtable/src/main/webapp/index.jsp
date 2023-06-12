<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>

<link href="css/metro/blue/jtable.css" rel="stylesheet" type="text/css" />
<link href="css/jquery-ui-1.10.3.custom.css" rel="stylesheet"type="text/css" />
<script src="js/jquery-1.8.2.js" type="text/javascript"></script>
<script src="js/jquery-ui-1.10.3.custom.js" type="text/javascript"></script>
<script src="js/jquery.jtable.js" type="text/javascript"></script>
<script>
	$(document).ready(function() {
		$('#StudentTableContainer').jtable({
			title: 'Table of students',
			messages: {
			    serverCommunicationError: 'An error occured while communicating to the server.',
			    loadingMessage: 'Loading records...',
			    noDataAvailable: 'No data available!',
			    addNewRecord: 'Add Employee',
			    editRecord: 'Edit Employee',
			    areYouSure: 'Are you sure?',
			    deleteConfirmation: 'This record will be deleted. Are you sure?',
			    save: 'Save',
			    saving: 'Saving',
			    cancel: 'Cancel',
			    deleteText: 'Delete',
			    deleting: 'Deleting',
			    error: 'Error',
			    close: 'Close',
			    cannotLoadOptionsFor: 'Can not load options for field {0}',
			    pagingInfo: 'Showing {0}-{1} of {2}',
			    pageSizeChangeLabel: 'Row count',
			    gotoPageLabel: 'Go to page',
			    canNotDeletedRecords: 'Can not deleted {0} of {1} records!',
			    deleteProggress: 'Deleted {0} of {1} records, processing...'
			},
			actions: {
				listAction: 'listStudentAction', // Display records
				createAction: 'createStudentAction', // Add new record
				updateAction: 'updateStudentAction', // Edit record
				deleteAction: 'deleteStudentAction' // Delete record
			},
			fields: {
				stdid: {
					title: 'ID',
					key: true,
					create: false,
					edit: false,
					list: true
				},
				stdname: {
					title: 'Name',
					create: true,
					edit: true
				},
				email: {
					title: 'Email',
					create: true,
					edit: true
				},
				age: {
					title: 'Age',
					create: true,
					edit: true
				}
			}
		});
		$('#StudentTableContainer').jtable('load');
	});
</script>
</head>
<body>
	<div style="width: 80%; margin-right: 10%; margin-left: 10%; text-align: center;">
		<h3>CRUD operations in jTable</h3>
		<div id="StudentTableContainer"></div>
	</div>
</body>
</html>