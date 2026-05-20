/* ===== 23e128760 telegram.handlers.system_handler:11 ===== */
/* ghidra_name=forced_23e128760 entry=23e128760 size=1771 */

longlong forced_23e128760(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  undefined4 uVar12;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar8 = DAT_23eeaaea0;
  if (DAT_23eeaaea0 == (longlong *)0x0) {
LAB_23e128797:
    DAT_23eeaaea0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaae90,DAT_23eeaae98,8);
  }
  else {
    lVar11 = *DAT_23eeaaea0;
    if (1 < lVar11) {
      *DAT_23eeaaea0 = lVar11 + -1;
      goto LAB_23e128797;
    }
    if (DAT_23eeaaea0[2] != 0) {
      *DAT_23eeaaea0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e128797;
    }
  }
  plVar2 = DAT_23eeaaea0;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar8 = DAT_23eeaaea0 + 9;
  lVar1 = *(longlong *)(lVar11 + 8);
  DAT_23eeaaea0[0xf] = lVar1;
  *(longlong **)(lVar11 + 8) = plVar8;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar2[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  lVar1 = DAT_23eea8590;
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar11 = *(longlong *)(lVar1 + 0x20);
  if (*(char *)(lVar11 + 10) == '\0') {
    plVar8 = (longlong *)FUN_23a37a020(lVar1,DAT_23eea85a0);
    if (plVar8 == (longlong *)0x0) goto LAB_23e128a81;
    lVar11 = *plVar8;
LAB_23e128de8:
    if (lVar11 == 0) goto LAB_23e128a81;
  }
  else {
    iVar7 = *(int *)(lVar11 + 0xc);
    if (*(int *)(lVar11 + 0xc) == 0) {
      *(int *)(lVar11 + 0xc) = DAT_23ec14c30;
      iVar7 = DAT_23ec14c30;
      DAT_23ec14c30 = DAT_23ec14c30 + 1;
    }
    if (DAT_23ec14c34 != iVar7) {
      DAT_23ec14c34 = iVar7;
      DAT_23eeaae88 = FUN_23e8cbd60(lVar11,DAT_23eea85a0,*(undefined8 *)(DAT_23eea85a0 + 0x18));
    }
    if (-1 < DAT_23eeaae88) {
      lVar1 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
      if (*(longlong *)(lVar1 + 8 + DAT_23eeaae88 * 0x10) != 0) goto LAB_23e128887;
      DAT_23eeaae88 = FUN_23e8cbd60(lVar11,DAT_23eea85a0,*(undefined8 *)(DAT_23eea85a0 + 0x18));
      if (-1 < DAT_23eeaae88) {
        lVar11 = *(longlong *)(lVar1 + 8 + DAT_23eeaae88 * 0x10);
        goto LAB_23e128de8;
      }
    }
LAB_23e128a81:
    plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea85a0);
    if ((plVar8 == (longlong *)0x0) || (*plVar8 == 0)) {
      uVar12 = 0xd;
      plVar8 = (longlong *)0x0;
      FUN_23e915740(param_1,&uStack_68,DAT_23eea85a0);
      uVar4 = uStack_68;
      uVar5 = uStack_60;
      plVar9 = DAT_23ed6a4f8;
      goto joined_r0x00023e128ca5;
    }
  }
LAB_23e128887:
  *(undefined4 *)(plVar2 + 5) = 0xd;
  plVar8 = (longlong *)FUN_23e91a870(param_1);
  if (plVar8 == (longlong *)0x0) {
    uVar4 = *(undefined8 *)(param_1 + 0x60);
    uVar12 = 0xd;
    plStack_58 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar5 = *(undefined8 *)(param_1 + 0x68);
    plVar9 = DAT_23ed6a4f8;
  }
  else {
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23eea85a8);
    lVar11 = DAT_23eea85b0;
    if (plVar9 != (longlong *)0x0) {
      *(undefined4 *)(plVar2 + 5) = 0xe;
      plVar10 = (longlong *)FUN_23e9186b0(param_1,plVar9,lVar11 + 0x18,DAT_23eea85b8);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (plVar10 != (longlong *)0x0) {
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23eea85a8);
        lVar11 = DAT_23eea85c0;
        if (plVar9 != (longlong *)0x0) {
          *(undefined4 *)(plVar2 + 5) = 0xf;
          plVar10 = (longlong *)FUN_23e9186b0(param_1,plVar9,lVar11 + 0x18,DAT_23eea85b8);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (plVar10 != (longlong *)0x0) {
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            lVar11 = DAT_23eea85d0;
            *(undefined4 *)(plVar2 + 5) = 0x10;
            plVar9 = (longlong *)
                     FUN_23e915840(param_1,plVar8,DAT_23eea85c8,*(undefined8 *)(lVar11 + 0x18));
            if (plVar9 == (longlong *)0x0) {
              uVar4 = *(undefined8 *)(param_1 + 0x60);
              uVar12 = 0x10;
              plStack_58 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar5 = *(undefined8 *)(param_1 + 0x68);
              plVar9 = DAT_23ed6a4f8;
            }
            else {
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              *(undefined4 *)(plVar2 + 5) = 0x11;
              lVar11 = FUN_23e91bfe0(param_1,plVar8,DAT_23eea85d8);
              if (lVar11 != 0) {
                lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar2 = *(longlong **)(lVar1 + 0x28);
                plVar9 = (longlong *)plVar2[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar1 + 0x30);
                *(undefined4 *)(plVar2 + 8) = 0xffffffff;
                if (plVar9 != (longlong *)0x0) {
                  plVar2[2] = 0;
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))();
                  }
                }
                *plVar2 = *plVar2 + -1;
                if (*plVar2 == 0) {
                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                }
                plVar2[0xf] = 0;
                *plVar8 = *plVar8 + -1;
                if (*plVar8 != 0) {
                  return lVar11;
                }
                (**(code **)(plVar8[1] + 0x30))(plVar8);
                return lVar11;
              }
              uVar4 = *(undefined8 *)(param_1 + 0x60);
              uVar12 = 0x11;
              plStack_58 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar5 = *(undefined8 *)(param_1 + 0x68);
              plVar9 = DAT_23ed6a4f8;
            }
            goto joined_r0x00023e128ca5;
          }
        }
        uVar4 = *(undefined8 *)(param_1 + 0x60);
        uVar12 = 0xf;
        plStack_58 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar5 = *(undefined8 *)(param_1 + 0x68);
        plVar9 = DAT_23ed6a4f8;
        goto joined_r0x00023e128ca5;
      }
    }
    plStack_58 = *(longlong **)(param_1 + 0x70);
    uVar4 = *(undefined8 *)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar12 = 0xe;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar5 = *(undefined8 *)(param_1 + 0x68);
    plVar9 = DAT_23ed6a4f8;
  }
joined_r0x00023e128ca5:
  DAT_23ed6a4f8 = plVar9;
  if (plStack_58 == (longlong *)0x0) {
    if (plVar9 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar9;
      *plVar9 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar10 = plVar9;
    }
    pcVar6 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar11 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar12;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar1 = plVar10[-1];
    puVar3 = *(undefined8 **)(lVar11 + 8);
    *puVar3 = plVar10 + -2;
    plVar10[-2] = lVar11;
    plVar10[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar11 + 8) = plVar10 + -2;
  }
  else {
    plVar10 = plStack_58;
    if ((longlong *)plStack_58[3] != plVar2) {
      if (plVar9 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar9;
        *plVar9 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar10 = plVar9;
      }
      pcVar6 = _PyRuntime_exref;
      plVar10[3] = (longlong)plVar2;
      *plVar2 = *plVar2 + 1;
      lVar11 = *(longlong *)(pcVar6 + 0x1f8);
      *(undefined4 *)((longlong)plVar10 + 0x24) = uVar12;
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
      lVar1 = plVar10[-1];
      puVar3 = *(undefined8 **)(lVar11 + 8);
      *puVar3 = plVar10 + -2;
      plVar10[-2] = lVar11;
      plVar10[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
      lVar1 = *plStack_58;
      *(longlong **)(lVar11 + 8) = plVar10 + -2;
      plVar10[2] = (longlong)plStack_58;
      if (lVar1 == 0) {
        (**(code **)(plStack_58[1] + 0x30))(plStack_58);
      }
    }
  }
  FUN_23e8bba40(plVar2,&DAT_23ec5a08d,plVar8);
  if (DAT_23eeaaea0 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    DAT_23eeaaea0 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar11 + 0x28);
  plVar9 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  plVar2[0xf] = 0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  FUN_23a33aa70(param_1,uVar4,uVar5,plVar10);
  return 0;
}
