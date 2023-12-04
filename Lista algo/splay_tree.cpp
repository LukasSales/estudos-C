#include <iostream>

using namespace std;

struct  tree{
    int val;
    tree* lt = NULL;
    tree* rt = NULL;
};

struct relac_find
{
    int profundidade = 0;
    tree* root;
    bool preenchido;
};

struct relac_insert{
    int profundidade = 0;
    tree* root;
};

struct relac_delet{
    int profundidade = 0;
    tree* root;
    bool preenchido = true;
    bool rotation = false;
};

struct relac_delet_min{
    tree* root;
    int value;
};

tree*  rot_lt(tree* root){
    tree* aux_rootlf = root->rt;
    root->rt = aux_rootlf->lt;
    aux_rootlf->lt = root;
    return aux_rootlf;
}

tree*  rot_rt(tree* root){
    tree* aux_rootrt = root->lt;
    root->lt = aux_rootrt->rt;
    aux_rootrt->rt = root;
    return aux_rootrt;
}

relac_delet_min delet_min(tree* root){
    relac_delet_min retorno;

    if (root->lt == NULL){
        retorno.value = root->val;
        retorno.root = root->rt;
        free(root);
        return retorno;
    }
    else{
        relac_delet_min retorno2 = delet_min(root->lt);
        root->lt = retorno2.root;
        retorno2.root = root;
        
        return retorno2;
    }
}
relac_delet bst_delete(tree*root, int chave){
    relac_delet retorno;

    if(root == NULL){
        retorno.root = root;
        retorno.rotation = false;
        retorno.preenchido = false;
        
        return retorno;
    }
    if(chave == root->val){
        retorno.rotation = true;

        if(root->lt != NULL && root->rt != NULL){
            relac_delet_min retorno1 = delet_min(root->rt);
            root->rt = retorno1.root;
            root->val = retorno1.value;

            retorno.root = root;
            return retorno;
        }
        else if (root->lt == NULL)
        {
            retorno.root = root->rt;
            free(root);

            return retorno;
        }
        else if (root->rt == NULL)
        {
            retorno.root = root->lt;
            free(root);

            return retorno;
        }
    }
    else{
        if(chave < root->val){ 
            relac_delet retorno2 = bst_delete(root->lt,chave);
            retorno.profundidade = (retorno2.profundidade + 1);
            root->lt = retorno2.root;
            retorno.preenchido = retorno2.preenchido;

            if(retorno.preenchido == true and retorno2.rotation == false ){
                root = rot_rt(root);
            }
            retorno.root = root;

            return retorno;
        }
        else{
            relac_delet retorno3 = bst_delete(root->rt,chave);
            retorno.profundidade = (retorno3.profundidade + 1);
            root->rt = retorno3.root;

            retorno.preenchido = retorno3.preenchido;

            if(retorno.preenchido == true and retorno3.rotation == false ){
                root = rot_lt(root);
            }
            retorno.root = root;
            return retorno;
        }
    }

}

relac_find find(tree*root, int chave){
    relac_find retornofinal;

    if (root == NULL){
        retornofinal.root = root;
        retornofinal.preenchido = false;

        return retornofinal;
    }
    else if (root->val == chave)
    {
        retornofinal.preenchido = true;
        retornofinal.root = root;

        return retornofinal;
    }
    else if (chave < root->val) {// está na esquerda
        relac_find retorno1 = find(root->lt, chave);
        retornofinal.profundidade = (retorno1.profundidade +1);
        root->lt = retorno1.root;
        retornofinal.preenchido = retorno1.preenchido;

        if(retornofinal.preenchido == true){
            root = rot_rt(root);
        }
        retornofinal.root = root;
        return retornofinal;
    }
    else if (chave > root->val){
        relac_find retorno2 = find(root->rt,chave);
        retornofinal.profundidade = (retorno2.profundidade + 1);
        retornofinal.preenchido = retorno2.preenchido;
        root->rt = retorno2.root; 

        if(retornofinal.preenchido == true){
            root = rot_lt(root);
        }

        retornofinal.root = root;
        return retornofinal;
    }    
}

relac_insert insert(tree* root, int chave){
    relac_insert retorno1;

    if(root == NULL){
        tree* p = new tree();
        p->val = chave;
        p->lt = NULL;
        p->rt = NULL;

        retorno1.root = p;
        return retorno1;
    }

    else if (root->val == chave){
        retorno1.root = root;
        return retorno1; 
    }
    else if (chave < root->val)
    {
        relac_insert retorno2 = insert(root->lt,chave);
        root->lt = retorno2.root;
        retorno1.profundidade = (retorno2.profundidade + 1); 
 
        root = rot_rt(root);
        retorno1.root = root;
        return retorno1;

    }
    else if (chave> root->val)
    {
        relac_insert retorno3 = insert(root->rt,chave);
        root->rt = retorno3.root;
        retorno1.profundidade = (retorno3.profundidade + 1); 

        root = rot_lt(root);
        retorno1.root = root;
        
        return retorno1;
    }
}

int main(){
    string acao;
    int numero;
    tree* curso = NULL;

    while ((acao != "END")){
        cin>>acao;
        
        if (acao =="INS"){
            cin>>numero;

            relac_insert final_insert = insert (curso,numero); 
            curso = final_insert.root;
            cout<<final_insert.profundidade<<endl;
            
        }
        else if (acao == "FND"){
            cin>>numero;

            relac_find final_find = find(curso,numero);
            curso = final_find.root;
            cout<<final_find.profundidade<<endl;
        }
        else if (acao == "DEL"){
            cin>>numero;
            relac_delet final_del = bst_delete(curso,numero);
            cout<<final_del.profundidade<<endl;
            curso = final_del.root;
        }
    }   
    return 0;
};