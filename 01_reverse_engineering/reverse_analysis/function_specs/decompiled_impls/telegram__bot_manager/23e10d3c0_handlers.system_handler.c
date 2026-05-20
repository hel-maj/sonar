/* ===== 23e10d3c0 telegram.bot_manager:? ===== */
/* ghidra_name=FUN_23e10d3c0 entry=23e10d3c0 size=1486 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e10d3c0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  code *pcVar9;
  char cVar10;
  longlong *plVar11;
  undefined4 uVar12;
  longlong *plVar13;
  longlong *plVar14;
  undefined8 uVar15;
  undefined8 uStack_58;
  
  plVar13 = _DAT_23eeab478;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  plVar4 = (longlong *)param_3[3];
  if (_DAT_23eeab478 != (longlong *)0x0) {
    lVar5 = *_DAT_23eeab478;
    if (lVar5 < 2) {
      if (_DAT_23eeab478[2] == 0) goto LAB_23e10d42c;
      *_DAT_23eeab478 = lVar5 + -1;
      if (lVar5 + -1 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
    }
    else {
      *_DAT_23eeab478 = lVar5 + -1;
    }
  }
  _DAT_23eeab478 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeab468,DAT_23eeab470,0x20);
LAB_23e10d42c:
  plVar7 = _DAT_23eeab478;
  lVar5 = *(longlong *)(param_1 + 0x38);
  plVar13 = _DAT_23eeab478 + 9;
  lVar6 = *(longlong *)(lVar5 + 8);
  _DAT_23eeab478[0xf] = lVar6;
  *(longlong **)(lVar5 + 8) = plVar13;
  if ((lVar6 != 0) &&
     (((*(char *)(lVar6 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar6 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar6 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar6 + 0x38))
       ) && (plVar7[0xe] != 0)))) {
    plVar13 = *(longlong **)(lVar6 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar13;
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  uVar15 = DAT_23eea98a0;
  *(undefined4 *)(plVar7 + 8) = 0;
  cVar10 = FUN_23e8d9ac0(plVar1,uVar15,plVar2);
  if (cVar10 == '\0') {
    uStack_58 = *(undefined8 *)(param_1 + 0x60);
    uVar15 = *(undefined8 *)(param_1 + 0x68);
    uVar12 = 0x20;
    plVar13 = *(longlong **)(param_1 + 0x70);
  }
  else {
    cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eea98a8,plVar3);
    if (cVar10 == '\0') {
      uStack_58 = *(undefined8 *)(param_1 + 0x60);
      uVar15 = *(undefined8 *)(param_1 + 0x68);
      uVar12 = 0x21;
      plVar13 = *(longlong **)(param_1 + 0x70);
    }
    else {
      cVar10 = FUN_23e8d9ac0(plVar1,_DAT_23eea98b0,plVar4);
      pcVar9 = _Py_NoneStruct_exref;
      if (cVar10 == '\0') {
        uStack_58 = *(undefined8 *)(param_1 + 0x60);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        uVar12 = 0x22;
        plVar13 = *(longlong **)(param_1 + 0x70);
      }
      else {
        cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eea98b8,_Py_NoneStruct_exref);
        if (cVar10 == '\0') {
          uStack_58 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = *(undefined8 *)(param_1 + 0x68);
          uVar12 = 0x24;
          plVar13 = *(longlong **)(param_1 + 0x70);
        }
        else {
          cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eea98c0,pcVar9);
          if (cVar10 == '\0') {
            uStack_58 = *(undefined8 *)(param_1 + 0x60);
            uVar15 = *(undefined8 *)(param_1 + 0x68);
            uVar12 = 0x25;
            plVar13 = *(longlong **)(param_1 + 0x70);
          }
          else {
            cVar10 = FUN_23e8d9ac0(plVar1,_DAT_23eea98c8,_Py_FalseStruct_exref);
            if (cVar10 == '\0') {
              uStack_58 = *(undefined8 *)(param_1 + 0x60);
              uVar15 = *(undefined8 *)(param_1 + 0x68);
              uVar12 = 0x26;
              plVar13 = *(longlong **)(param_1 + 0x70);
            }
            else {
              cVar10 = FUN_23e8d9ac0(plVar1,_DAT_23eea98d0,pcVar9);
              if (cVar10 == '\0') {
                uStack_58 = *(undefined8 *)(param_1 + 0x60);
                uVar15 = *(undefined8 *)(param_1 + 0x68);
                uVar12 = 0x28;
                plVar13 = *(longlong **)(param_1 + 0x70);
              }
              else {
                cVar10 = FUN_23e8d9ac0(plVar1,_DAT_23eea98d8,pcVar9);
                if (cVar10 != '\0') {
                  lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar13 = *(longlong **)(lVar5 + 0x28);
                  plVar7 = (longlong *)plVar13[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar5 + 0x30)
                  ;
                  *(undefined4 *)(plVar13 + 8) = 0xffffffff;
                  if (plVar7 != (longlong *)0x0) {
                    plVar13[2] = 0;
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      (**(code **)(plVar7[1] + 0x30))();
                    }
                  }
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
                  plVar13[0xf] = 0;
                  *plVar1 = *plVar1 + -1;
                  if (*plVar1 == 0) {
                    (**(code **)(plVar1[1] + 0x30))(plVar1);
                  }
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 == 0) {
                    (**(code **)(plVar2[1] + 0x30))(plVar2);
                  }
                  *plVar3 = *plVar3 + -1;
                  if (*plVar3 == 0) {
                    (**(code **)(plVar3[1] + 0x30))(plVar3);
                  }
                  *plVar4 = *plVar4 + -1;
                  if (*plVar4 != 0) {
                    return pcVar9;
                  }
                  (**(code **)(plVar4[1] + 0x30))(plVar4);
                  return pcVar9;
                }
                uStack_58 = *(undefined8 *)(param_1 + 0x60);
                uVar15 = *(undefined8 *)(param_1 + 0x68);
                uVar12 = 0x29;
                plVar13 = *(longlong **)(param_1 + 0x70);
              }
            }
          }
        }
      }
    }
  }
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar11 = DAT_23ed6a4f8;
  if (plVar13 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar13 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar13;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar5 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar12;
    lVar5 = *(longlong *)(lVar5 + 0x10);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar5 = *(longlong *)(lVar5 + 0x2e8);
    lVar6 = plVar11[-1];
    puVar8 = *(undefined8 **)(lVar5 + 8);
    *puVar8 = plVar11 + -2;
    plVar11[-2] = lVar5;
    plVar11[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar8;
    *(longlong **)(lVar5 + 8) = plVar11 + -2;
    plVar14 = plVar11;
  }
  else {
    plVar14 = plVar13;
    if ((longlong *)plVar13[3] != plVar7) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar14 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar11[3] = (longlong)plVar7;
      *plVar7 = *plVar7 + 1;
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar12;
      pcVar9 = _PyRuntime_exref;
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar9 + 0x1f8) + 0x10) + 0x2e8);
      lVar6 = plVar11[-1];
      puVar8 = *(undefined8 **)(lVar5 + 8);
      *puVar8 = plVar11 + -2;
      plVar11[-2] = lVar5;
      plVar11[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar8;
      lVar6 = *plVar13;
      *(longlong **)(lVar5 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar13;
      plVar14 = plVar11;
      if (lVar6 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
    }
  }
  FUN_23e8bba40(plVar7,&DAT_23ec5a149,plVar1,plVar2,plVar3,plVar4);
  if (_DAT_23eeab478 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    _DAT_23eeab478 = (longlong *)0x0;
  }
  lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar13 = *(longlong **)(lVar5 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar5 + 0x30);
  plVar7 = (longlong *)plVar13[2];
  *(undefined4 *)(plVar13 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar13[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  plVar13[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,uStack_58,uVar15,plVar14);
  return (code *)0x0;
}
