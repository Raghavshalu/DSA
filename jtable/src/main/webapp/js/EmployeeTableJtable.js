$(document).ready(function() {
	$('#EmployeeTableContainer').jtable({
		title : 'Employee List',
		actions : {
			listAction : 'listAction',
			createAction : 'createAction',
			updateAction : 'updateAction',
			deleteAction : 'deleteAction'
		},

		fields : {
			empid : {
				title : 'Empid',
				width : '20%',
				key : true,
				list : true,
				edit : false,
				create : true
			},
			empname : {
				title : 'Empname',
				width : '20%',
				edit : true
			},
			designation : {
				title : 'Designation',
				width : '20%',
				edit : true
			},
			deptid : {
				title : 'Deptid',
				width : '20%',
				edit : true
			},
			address : {
				title : 'Address',
				width : '30%',
				edit : true
			},
			phone : {
				title : 'Phone',
				width : '10%',
				edit : true
			},
			email : {
				title : 'Email',
				width : '10%',
				edit : true
			},
			mobile : {
				title : 'Mobile',
				width : '15%',
				edit : true
			},
			status : {
				title : 'Status',
				width : '10%',
				edit : true
			},
			createdate : {
				title : 'Createdate',
				width : '15%',
				edit : true
			},
			createby : {
				title : 'Createby',
				width : '10%',
				edit : true
			},
		}
	});
	$('#EmployeeTableContainer').jtable('load');
});