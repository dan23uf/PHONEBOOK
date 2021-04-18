//Contact Class
class Contact{
    constructor(name,phone,address,hoursOfOperation){
        this.name=name;
        this.phone = phone;
        this.address = address;
        this.hoursOfOperation = hoursOfOperation;
    }
}

//UI Class
class UI{
    static displayContacts(){

        const contacts = Store.getContact();
        contacts.forEach((contact) => UI.addContactToList(contact));
    }

    static addContactToList(contact){
        const list = document.querySelector('#contact-list');

        const row = document.createElement('tr');
        row.innerHTML = `
        <td>${contact.name}</td>
        <td>${contact.phone}</td>
        <td><a href="#" class="btn btn-danger btn-sm delete">X</a></td>
        `;

        list.appendChild(row);
    }

    static deleteContact(el){
        if(el.classList.contains('delete')){
            el.parentElement.parentElement.remove();
        }
    }

    static showAlert(message, className) {
        const div = document.createElement('div');
        div.className = `alert alert-${className}`;
        div.appendChild(document.createTextNode(message))
        const container = document.querySelector('.container');
        const form = document.querySelector('#phonebook-form')
        container.insertBefore(div, form);
        //Vanish in 3 seconds
        setTimeout(() => document.querySelector('.alert').remove(),
            3000);
    }

    static clearFields () {
        document.querySelector('#name').value = '';
        document.querySelector('#phone').value = '';
    }
}
//Stored Class
class Store {
    static getContact(){
        let contacts;
        if(localStorage.getItem('contacts') === null){
            contacts = [];
        }else{
            contacts = JSON.parse(localStorage.getItem('contacts'));
        }

        return contacts;
    }

    static addContact(contact){
        const contacts = Store.getContact();

        contacts.push(contact);

        localStorage.setItem('contacts', JSON.stringify(contacts));
    }

    static removeContact(name){
        const contacts = Store.getContact();

        contacts.forEach((contact, index) => {
            if(contact.name === name){
                contacts.splice(index,1);
            }
        });

        localStorage.setItem('contacts', JSON.stringify(contacts));
    }
}

//Event: Display Contact
document.addEventListener('DOMContentLoaded', UI.displayContacts);

//Event: Add Contact
document.querySelector('#phonebook-form').addEventListener('submit',(e) => {
    e.preventDefault();
  //Get form value
  const name = document.querySelector('#name').value;
  const phone = document.querySelector('#phone').value;

  //Validate
    if(name === '' || phone === '' ){
        UI.showAlert('Please fill in all fields', 'danger');
    }else{
        //Instantiate book
        const contact = new Contact(name, phone);

        //Add contact
        UI.addContactToList(contact);

        Store.addContact(contact);
        UI.showAlert('Book added','success')

        //Clear fields
        UI.clearFields();
    }
});

//Event: Remove Contact
document.querySelector('#contact-list').addEventListener('click', (e) =>
{
    //Remove book from UI
    UI.deleteContact(e.target)

    //Remove book from store
    Store.removeContact(e.target.parentElement.previousElementSibling.previousElementSibling.textContent);

    UI.showAlert('Book remove','success')

});