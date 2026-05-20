/* ===== 23e2eab40 ui.hotkey_listener:103 ===== */
/* ghidra_name=FUN_23e2eab40 entry=23e2eab40 size=1749 */

code * FUN_23e2eab40(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  code *pcVar7;
  char cVar8;
  int iVar9;
  longlong *plVar10;
  undefined8 uVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined4 uVar14;
  
  plVar12 = DAT_23eeb0118;
  plVar1 = (longlong *)*param_3;
  if (DAT_23eeb0118 == (longlong *)0x0) {
LAB_23e2eab7a:
    DAT_23eeb0118 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0110,DAT_23eeb0170,8);
  }
  else {
    lVar2 = *DAT_23eeb0118;
    if (1 < lVar2) {
      *DAT_23eeb0118 = lVar2 + -1;
      goto LAB_23e2eab7a;
    }
    if (DAT_23eeb0118[2] != 0) {
      *DAT_23eeb0118 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e2eab7a;
    }
  }
  plVar4 = DAT_23eeb0118;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar12 = DAT_23eeb0118 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  DAT_23eeb0118[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar12;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  pcVar7 = _Py_FalseStruct_exref;
  *(undefined4 *)(plVar4 + 8) = 0;
  cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eead0c0,pcVar7);
  if (cVar8 == '\0') {
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar14 = 0x69;
    uVar11 = *(undefined8 *)(param_1 + 0x60);
    uVar6 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e2ead95;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead0a0);
  if (plVar10 != (longlong *)0x0) {
    iVar9 = FUN_23a35f020(plVar10);
    lVar2 = *plVar10 + -1;
    if (iVar9 == -1) {
      uVar11 = *(undefined8 *)(param_1 + 0x60);
      uVar6 = *(undefined8 *)(param_1 + 0x68);
      uVar14 = 0x6a;
      plVar12 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar10 = lVar2;
      plVar13 = DAT_23ed6a4f8;
      if (lVar2 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        plVar13 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023e2ead95;
    }
    *plVar10 = lVar2;
    if (lVar2 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (iVar9 == 0) goto LAB_23e2eac6d;
    plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead0a0);
    if (plVar12 != (longlong *)0x0) {
      *(undefined4 *)(plVar4 + 5) = 0x6a;
      plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar12,DAT_23eead148);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plVar13 != (longlong *)0x0) {
        iVar9 = FUN_23a35f020(plVar13);
        lVar2 = *plVar13 + -1;
        if (iVar9 == -1) {
          uVar11 = *(undefined8 *)(param_1 + 0x60);
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar13 = lVar2;
          if (lVar2 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          uVar14 = 0x6a;
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e2ead95;
        }
        *plVar13 = lVar2;
        if (lVar2 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if (iVar9 == 1) {
          plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead0a0);
          if (plVar12 != (longlong *)0x0) {
            plVar13 = (longlong *)FUN_23e8bc2f0(plVar12,DAT_23eead150);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            lVar2 = DAT_23eead158;
            if (plVar13 != (longlong *)0x0) {
              *(undefined4 *)(plVar4 + 5) = 0x6b;
              plVar12 = (longlong *)FUN_23e9186b0(param_1,plVar13,lVar2 + 0x18,DAT_23eead160);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              if (plVar12 != (longlong *)0x0) {
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                goto LAB_23e2eac6d;
              }
            }
          }
          uVar11 = *(undefined8 *)(param_1 + 0x60);
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          uVar14 = 0x6b;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar13 = DAT_23ed6a4f8;
        }
        else {
LAB_23e2eac6d:
          pcVar7 = _Py_NoneStruct_exref;
          cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eead0a0,_Py_NoneStruct_exref);
          if (cVar8 == '\0') {
            uVar11 = *(undefined8 *)(param_1 + 0x60);
            uVar6 = *(undefined8 *)(param_1 + 0x68);
            uVar14 = 0x6c;
            plVar12 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar13 = DAT_23ed6a4f8;
          }
          else {
            uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
            *(undefined4 *)(plVar4 + 5) = 0x6d;
            plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar11,DAT_23eead1a8);
            if (plVar12 != (longlong *)0x0) {
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar12 = *(longlong **)(lVar2 + 0x28);
              plVar4 = (longlong *)plVar12[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
              *(undefined4 *)(plVar12 + 8) = 0xffffffff;
              if (plVar4 != (longlong *)0x0) {
                plVar12[2] = 0;
                *plVar4 = *plVar4 + -1;
                if (*plVar4 == 0) {
                  (**(code **)(plVar4[1] + 0x30))();
                }
              }
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *(longlong *)pcVar7 = *(longlong *)pcVar7 + 1;
              plVar12[0xf] = 0;
              *plVar1 = *plVar1 + -1;
              if (*plVar1 != 0) {
                return pcVar7;
              }
              (**(code **)(plVar1[1] + 0x30))(plVar1);
              return pcVar7;
            }
            uVar11 = *(undefined8 *)(param_1 + 0x60);
            uVar6 = *(undefined8 *)(param_1 + 0x68);
            uVar14 = 0x6d;
            plVar12 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar13 = DAT_23ed6a4f8;
          }
        }
        goto joined_r0x00023e2ead95;
      }
    }
  }
  plVar12 = *(longlong **)(param_1 + 0x70);
  uVar11 = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar6 = *(undefined8 *)(param_1 + 0x68);
  uVar14 = 0x6a;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar13 = DAT_23ed6a4f8;
joined_r0x00023e2ead95:
  DAT_23ed6a4f8 = plVar13;
  if (plVar12 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar10 = plVar13;
    }
    pcVar7 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar14;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar10[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar10 + -2;
    plVar10[-2] = lVar2;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar10 + -2;
  }
  else {
    plVar10 = plVar12;
    if ((longlong *)plVar12[3] != plVar4) {
      if (plVar13 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar13;
        *plVar13 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar10 = plVar13;
      }
      pcVar7 = _PyRuntime_exref;
      plVar10[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar2 = *(longlong *)(pcVar7 + 0x1f8);
      *(undefined4 *)((longlong)plVar10 + 0x24) = uVar14;
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar3 = plVar10[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar10 + -2;
      plVar10[-2] = lVar2;
      plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar12;
      *(longlong **)(lVar2 + 8) = plVar10 + -2;
      plVar10[2] = (longlong)plVar12;
      if (lVar3 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5b149,plVar1);
  if (DAT_23eeb0118 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23eeb0118 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar12 = *(longlong **)(lVar2 + 0x28);
  plVar4 = (longlong *)plVar12[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar12 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar12[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  plVar12[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar11,uVar6,plVar10);
  return (code *)0x0;
}
