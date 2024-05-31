import { _decorator, Component, Node, director } from 'cc';
const { ccclass, property } = _decorator;

@ccclass('data')
export class data extends Component {
    @property(Node)stage:Node
    data=[];

    start() {
        this.init();
        director.addPersistRootNode(this.node);
    }

    init(){
        for(let i=0;i<this.stage.children.length;i++){
            data[i]=0;
        }
    }

    public setData(key:number,value:number){
        data[key]=value;
    }

    public getData(key:number){
        return data[key];
    }

    update(deltaTime: number) {
        
    }
}


