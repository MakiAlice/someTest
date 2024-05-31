import { _decorator, Component, Node, Label } from 'cc';
const { ccclass, property } = _decorator;

@ccclass('coin')
export class coin extends Component {
    @property(Node)coin:Node;
    start() {
      this.schedule(()=>{
        let l=parseInt(this.coin.getComponent(Label).string);
        l+=1;
        this.coin.getComponent(Label).string=l.toString();},1)
    }

    update(deltaTime: number) {
        
    }
}


