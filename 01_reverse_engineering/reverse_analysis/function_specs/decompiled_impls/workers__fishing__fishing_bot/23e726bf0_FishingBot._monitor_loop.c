/* ===== 23e726bf0 workers.fishing.fishing_bot:FishingBot._monitor_loop ===== */
/* ghidra_name=FUN_23e726bf0 entry=23e726bf0 size=5162 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e726bf0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  code *pcVar21;
  longlong *plStack_98;
  longlong *plStack_90;
  longlong *plStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  
  plVar10 = _DAT_23eedae60;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eedae60 == (longlong *)0x0) {
LAB_23e726c45:
    _DAT_23eedae60 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaf38,DAT_23eedaeb8,0x3c);
  }
  else {
    lVar11 = *_DAT_23eedae60;
    if (1 < lVar11) {
      *_DAT_23eedae60 = lVar11 + -1;
      goto LAB_23e726c45;
    }
    if (_DAT_23eedae60[2] != 0) {
      *_DAT_23eedae60 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e726c45;
    }
  }
  plVar5 = _DAT_23eedae60;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedae60 + 9;
  lVar3 = *(longlong *)(lVar11 + 8);
  _DAT_23eedae60[0xf] = lVar3;
  *(longlong **)(lVar11 + 8) = plVar10;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  uVar6 = DAT_23eed8d78;
  *(undefined4 *)(plVar5 + 5) = 0x120;
  plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar1,uVar6);
  if (plVar10 == (longlong *)0x0) {
    plStack_98 = *(longlong **)(param_1 + 0x60);
    plVar16 = *(longlong **)(param_1 + 0x70);
    pcVar15 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    plStack_90 = *(longlong **)(param_1 + 0x68);
    uVar19 = 0x120;
    uVar20 = 2;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e727490;
  }
  lVar11 = FUN_23e8e0ba0();
  if (lVar11 == 0) {
    FUN_23e915740(param_1,&plStack_78,DAT_23eed8c70);
    plStack_98 = plStack_78;
    plStack_90 = plStack_70;
    plVar12 = (longlong *)0x0;
    plVar16 = plStack_68;
  }
  else {
    *(undefined4 *)(plVar5 + 5) = 0x121;
    plVar12 = (longlong *)FUN_23e91bfe0(param_1,lVar11);
    if (plVar12 != (longlong *)0x0) {
      iVar8 = FUN_23e913250(plVar2,DAT_23eed8ca8);
      uVar6 = DAT_23eed8ca8;
      if (iVar8 == -1) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar16 = *(longlong **)(param_1 + 0x70);
        pcVar15 = (code *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar13 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        uVar20 = 0;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        uVar19 = 0x125;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e727490;
      }
      if (iVar8 == 1) {
        plVar14 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6ce40);
        plVar16 = DAT_23eed8d80;
        lVar11 = DAT_23ed6cce8;
        if (plVar14 == (longlong *)0x0) {
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar16 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar13 = (longlong *)0x0;
          uVar19 = 0x126;
          uVar20 = 0;
          plStack_90 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar14 = (longlong *)0x0;
          goto LAB_23e727490;
        }
        lVar3 = *(longlong *)(param_1 + 0x10);
        plVar13 = *(longlong **)(DAT_23ed6cce8 + 0x20);
        iVar8 = *(int *)(lVar3 + 0x1410);
        *plVar13 = *plVar13 + 1;
        if (iVar8 == 0) {
          plVar17 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
          plVar13 = *(longlong **)(lVar11 + 0x20);
        }
        else {
          iVar8 = iVar8 + -1;
          *(int *)(lVar3 + 0x1410) = iVar8;
          plVar17 = *(longlong **)(lVar3 + 0x1190 + (longlong)iVar8 * 8);
          *plVar17 = 1;
        }
        lVar11 = *(longlong *)(lVar11 + 0x28);
        plVar17[2] = 0;
        plVar17[4] = (longlong)plVar13;
        plVar17[5] = lVar11;
        plVar17[3] = 1;
        *(undefined4 *)(plVar5 + 5) = 0x126;
        plStack_78 = plVar16;
        plStack_70 = plVar17;
        plVar16 = (longlong *)FUN_23e94ed00(param_1,plVar14,&plStack_78);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        *plVar17 = *plVar17 + -1;
        if (*plVar17 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        if (plVar16 == (longlong *)0x0) {
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar16 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar14 = (longlong *)0x0;
          uVar19 = 0x126;
          uVar20 = 0;
          plStack_90 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = (longlong *)0x0;
          goto LAB_23e727490;
        }
        iVar8 = PySequence_Contains(plVar16,uVar6);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        if (iVar8 == -1) {
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar16 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar13 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          uVar20 = 0;
          plStack_90 = *(longlong **)(param_1 + 0x68);
          uVar19 = 0x126;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e727490;
        }
joined_r0x00023e727051:
        if (iVar8 == 1) {
          plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a10);
          if (plVar16 != (longlong *)0x0) {
            cVar7 = FUN_23a39bc50(param_1,plVar16,plVar2,plVar12);
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            pcVar15 = _Py_TrueStruct_exref;
            if (cVar7 == '\0') {
              plStack_98 = *(longlong **)(param_1 + 0x60);
              plVar16 = *(longlong **)(param_1 + 0x70);
              pcVar15 = (code *)0x0;
              uVar19 = 0x130;
              plVar13 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              uVar20 = 1;
              plStack_90 = *(longlong **)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e727490;
            }
            lVar11 = *(longlong *)(param_1 + 0x38);
            lVar3 = *(longlong *)(lVar11 + 8);
            *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
            plVar5 = *(longlong **)(lVar3 + 0x28);
            plVar16 = (longlong *)plVar5[2];
            *(undefined8 *)(lVar11 + 8) = *(undefined8 *)(lVar3 + 0x30);
            *(undefined4 *)(plVar5 + 8) = 0xffffffff;
            if (plVar16 != (longlong *)0x0) {
              plVar5[2] = 0;
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))();
              }
            }
            *plVar5 = *plVar5 + -1;
            if (*plVar5 == 0) {
              (**(code **)(plVar5[1] + 0x30))(plVar5);
            }
            plVar5[0xf] = 0;
            plVar13 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            pcVar21 = (code *)0x0;
            goto LAB_23e7271c5;
          }
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar16 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar13 = (longlong *)0x0;
          uVar19 = 0x130;
          uVar20 = 1;
          plStack_90 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar14 = (longlong *)0x0;
          goto LAB_23e727490;
        }
      }
      else {
        iVar8 = FUN_23e913250(plVar2,DAT_23eed8d88);
        uVar6 = DAT_23eed8d88;
        if (iVar8 == -1) {
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar16 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar13 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          uVar20 = 0;
          plStack_90 = *(longlong **)(param_1 + 0x68);
          uVar19 = 0x127;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e727490;
        }
        if (iVar8 == 1) {
          plVar14 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6ce40);
          plVar16 = DAT_23eed8d80;
          lVar11 = DAT_23ed6cce8;
          if (plVar14 == (longlong *)0x0) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            pcVar15 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar13 = (longlong *)0x0;
            uVar19 = 0x128;
            uVar20 = 0;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar14 = (longlong *)0x0;
            goto LAB_23e727490;
          }
          lVar3 = *(longlong *)(param_1 + 0x10);
          plVar13 = *(longlong **)(DAT_23ed6cce8 + 0x20);
          iVar8 = *(int *)(lVar3 + 0x1410);
          *plVar13 = *plVar13 + 1;
          if (iVar8 == 0) {
            plVar17 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
            plVar13 = *(longlong **)(lVar11 + 0x20);
          }
          else {
            iVar8 = iVar8 + -1;
            *(int *)(lVar3 + 0x1410) = iVar8;
            plVar17 = *(longlong **)(lVar3 + 0x1190 + (longlong)iVar8 * 8);
            *plVar17 = 1;
          }
          lVar11 = *(longlong *)(lVar11 + 0x28);
          plVar17[2] = 0;
          plVar17[4] = (longlong)plVar13;
          plVar17[5] = lVar11;
          plVar17[3] = 1;
          *(undefined4 *)(plVar5 + 5) = 0x128;
          plStack_78 = plVar16;
          plStack_70 = plVar17;
          plVar16 = (longlong *)FUN_23e94ed00(param_1,plVar14,&plStack_78);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          if (plVar16 == (longlong *)0x0) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            pcVar15 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar14 = (longlong *)0x0;
            uVar19 = 0x128;
            uVar20 = 0;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = (longlong *)0x0;
            goto LAB_23e727490;
          }
          iVar8 = PySequence_Contains(plVar16,uVar6);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (iVar8 == -1) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            pcVar15 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar13 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            uVar20 = 0;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            uVar19 = 0x128;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e727490;
          }
          goto joined_r0x00023e727051;
        }
        iVar8 = FUN_23e913250(plVar2,DAT_23eed8d90);
        uVar6 = DAT_23eed8d90;
        if (iVar8 == -1) {
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar16 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar13 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          uVar20 = 0;
          plStack_90 = *(longlong **)(param_1 + 0x68);
          uVar19 = 0x129;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e727490;
        }
        if (iVar8 == 1) {
          plVar14 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6ce40);
          plVar16 = DAT_23eed8d80;
          lVar11 = DAT_23ed6cce8;
          if (plVar14 == (longlong *)0x0) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            pcVar15 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar13 = (longlong *)0x0;
            uVar19 = 0x12a;
            uVar20 = 0;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar14 = (longlong *)0x0;
            goto LAB_23e727490;
          }
          lVar3 = *(longlong *)(param_1 + 0x10);
          plVar13 = *(longlong **)(DAT_23ed6cce8 + 0x20);
          iVar8 = *(int *)(lVar3 + 0x1410);
          *plVar13 = *plVar13 + 1;
          if (iVar8 == 0) {
            plVar17 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
            plVar13 = *(longlong **)(lVar11 + 0x20);
          }
          else {
            iVar8 = iVar8 + -1;
            *(int *)(lVar3 + 0x1410) = iVar8;
            plVar17 = *(longlong **)(lVar3 + 0x1190 + (longlong)iVar8 * 8);
            *plVar17 = 1;
          }
          lVar11 = *(longlong *)(lVar11 + 0x28);
          plVar17[2] = 0;
          plVar17[4] = (longlong)plVar13;
          plVar17[5] = lVar11;
          plVar17[3] = 1;
          *(undefined4 *)(plVar5 + 5) = 0x12a;
          plStack_78 = plVar16;
          plStack_70 = plVar17;
          plVar16 = (longlong *)FUN_23e94ed00(param_1,plVar14,&plStack_78);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          if (plVar16 == (longlong *)0x0) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            pcVar15 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar14 = (longlong *)0x0;
            uVar19 = 0x12a;
            uVar20 = 0;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = (longlong *)0x0;
            goto LAB_23e727490;
          }
          iVar8 = PySequence_Contains(plVar16,uVar6);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (iVar8 == -1) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            pcVar15 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar13 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            uVar20 = 0;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            uVar19 = 0x12a;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e727490;
          }
          goto joined_r0x00023e727051;
        }
        iVar8 = FUN_23e913250(plVar2,DAT_23eed8d98);
        plVar16 = DAT_23eed8d98;
        if (iVar8 == -1) {
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar16 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar13 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          uVar20 = 0;
          plStack_90 = *(longlong **)(param_1 + 0x68);
          uVar19 = 299;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e727490;
        }
        if (iVar8 == 1) {
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6ce40);
          plVar14 = DAT_23eed8d98;
          lVar11 = DAT_23ed6cce8;
          if (plVar13 == (longlong *)0x0) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            pcVar15 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar13 = (longlong *)0x0;
            uVar19 = 300;
            uVar20 = 0;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar14 = (longlong *)0x0;
            goto LAB_23e727490;
          }
          lVar3 = *(longlong *)(param_1 + 0x10);
          plVar17 = *(longlong **)(DAT_23ed6cce8 + 0x20);
          iVar8 = *(int *)(lVar3 + 0x1410);
          *plVar17 = *plVar17 + 1;
          if (iVar8 == 0) {
            plVar18 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
            plVar17 = *(longlong **)(lVar11 + 0x20);
          }
          else {
            iVar8 = iVar8 + -1;
            *(int *)(lVar3 + 0x1410) = iVar8;
            plVar18 = *(longlong **)(lVar3 + 0x1190 + (longlong)iVar8 * 8);
            *plVar18 = 1;
          }
          lVar11 = *(longlong *)(lVar11 + 0x28);
          plVar18[2] = 0;
          plVar18[4] = (longlong)plVar17;
          plVar18[5] = lVar11;
          plVar18[3] = 1;
          *(undefined4 *)(plVar5 + 5) = 300;
          plStack_78 = plVar14;
          plStack_70 = plVar18;
          plVar14 = (longlong *)FUN_23e94ed00(param_1,plVar13,&plStack_78);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))(plVar18);
          }
          if (plVar14 == (longlong *)0x0) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            pcVar15 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar14 = (longlong *)0x0;
            uVar19 = 300;
            uVar20 = 0;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = (longlong *)0x0;
            goto LAB_23e727490;
          }
          iVar8 = PySequence_Contains(plVar14,plVar16);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (iVar8 == -1) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            pcVar15 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar13 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            uVar20 = 0;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            uVar19 = 300;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e727490;
          }
          goto joined_r0x00023e727051;
        }
      }
      plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a10);
      plVar14 = (longlong *)0x0;
      if (plVar16 != (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23e8bc2f0(plVar16,DAT_23ed6ce40);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        if (plVar13 == (longlong *)0x0) {
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar16 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar14 = (longlong *)0x0;
          uVar19 = 0x134;
          uVar20 = 0;
          plStack_90 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = (longlong *)0x0;
          goto LAB_23e727490;
        }
        *(undefined4 *)(plVar5 + 5) = 0x134;
        plStack_70 = DAT_23ed6ccf0;
        plStack_78 = plVar2;
        plVar14 = (longlong *)FUN_23e94ed00(param_1,plVar13,&plStack_78);
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if (plVar14 != (longlong *)0x0) {
          plVar13 = (longlong *)FUN_23e8c6640(plVar12,plVar14);
          if (plVar13 == (longlong *)0x0) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            pcVar15 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar19 = 0x135;
            uVar20 = 0;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e727490;
          }
          plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a20);
          if (plVar16 == (longlong *)0x0) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            pcVar15 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar19 = 0x138;
            uVar20 = 0;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e727490;
          }
          pcVar15 = (code *)FUN_23e8d09c0(plVar13,plVar16);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (pcVar15 == (code *)0x0) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            uVar20 = 0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar19 = 0x138;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e727490;
          }
          uVar9 = FUN_23a35f020(pcVar15);
          if (uVar9 == 0xffffffff) {
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            uVar20 = 0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar19 = 0x13a;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e727490;
          }
          if (uVar9 == 0) {
            plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a10);
            if (plVar16 != (longlong *)0x0) {
              iVar8 = PySequence_Contains(plVar16,plVar2);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              if (iVar8 != -1) {
                if (iVar8 == 1) goto LAB_23e727abf;
                goto LAB_23e727173;
              }
            }
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x13a;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_90 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            uVar20 = 0;
            goto LAB_23e727490;
          }
          if ((uVar9 & 1) != 0) {
LAB_23e727173:
            lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar5 = *(longlong **)(lVar11 + 0x28);
            plVar16 = (longlong *)plVar5[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
            *(undefined4 *)(plVar5 + 8) = 0xffffffff;
            if (plVar16 != (longlong *)0x0) {
              plVar5[2] = 0;
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))();
              }
            }
            *plVar5 = *plVar5 + -1;
            if (*plVar5 == 0) {
              (**(code **)(plVar5[1] + 0x30))(plVar5);
            }
            plVar5[0xf] = 0;
            *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
            pcVar21 = pcVar15;
LAB_23e7271c5:
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if ((pcVar21 != (code *)0x0) &&
               (*(longlong *)pcVar21 = *(longlong *)pcVar21 + -1, *(longlong *)pcVar21 == 0)) {
              (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
            }
            lVar11 = *plVar1;
            *plVar1 = lVar11 + -1;
            if (lVar11 + -1 == 0) {
              (**(code **)(plVar1[1] + 0x30))(plVar1);
            }
            lVar11 = *plVar2;
            *plVar2 = lVar11 + -1;
            if (lVar11 + -1 != 0) {
              return pcVar15;
            }
            (**(code **)(plVar2[1] + 0x30))(plVar2);
            return pcVar15;
          }
LAB_23e727abf:
          plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a10);
          if (plVar16 != (longlong *)0x0) {
            iVar8 = PyObject_DelItem(plVar16,plVar2);
            lVar11 = *plVar16 + -1;
            *plVar16 = lVar11;
            if (iVar8 != -1) {
              if (lVar11 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              goto LAB_23e727173;
            }
            if (lVar11 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
          }
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar16 = *(longlong **)(param_1 + 0x70);
          uVar20 = 0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar19 = 0x13c;
          plStack_90 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e727490;
        }
      }
      plStack_98 = *(longlong **)(param_1 + 0x60);
      plVar16 = *(longlong **)(param_1 + 0x70);
      pcVar15 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar13 = (longlong *)0x0;
      uVar19 = 0x134;
      uVar20 = 0;
      plStack_90 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e727490;
    }
    plStack_98 = *(longlong **)(param_1 + 0x60);
    plVar16 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_90 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  pcVar15 = (code *)0x0;
  plVar13 = (longlong *)0x0;
  plVar14 = (longlong *)0x0;
  uVar19 = 0x121;
  uVar20 = 2;
LAB_23e727490:
  plVar17 = DAT_23ed6a4f8;
  if (plVar16 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar17 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar21 = _PyRuntime_exref;
    plVar17[3] = (longlong)plVar5;
    plVar17[2] = 0;
    *plVar5 = *plVar5 + 1;
    lVar11 = *(longlong *)(pcVar21 + 0x1f8);
    *(undefined4 *)((longlong)plVar17 + 0x24) = uVar19;
    *(undefined4 *)(plVar17 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar3 = plVar17[-1];
    puVar4 = *(undefined8 **)(lVar11 + 8);
    *puVar4 = plVar17 + -2;
    plVar17[-2] = lVar11;
    plVar17[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar11 + 8) = plVar17 + -2;
    plVar18 = plVar17;
  }
  else {
    plVar18 = plVar16;
    if ((longlong *)plVar16[3] != plVar5) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar17 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar18 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar17[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      *(undefined4 *)((longlong)plVar17 + 0x24) = uVar19;
      pcVar21 = _PyRuntime_exref;
      *(undefined4 *)(plVar17 + 4) = 0xffffffff;
      lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar21 + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar17[-1];
      puVar4 = *(undefined8 **)(lVar11 + 8);
      *puVar4 = plVar17 + -2;
      plVar17[-2] = lVar11;
      plVar17[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
      lVar3 = *plVar16;
      *(longlong **)(lVar11 + 8) = plVar17 + -2;
      plVar17[2] = (longlong)plVar16;
      plVar18 = plVar17;
      if (lVar3 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
    }
  }
  FUN_23e8bba40(plVar5,"oooobooo",plVar1,plVar2,plVar10,plVar12,uVar20,plVar14,plVar13,pcVar15);
  if (_DAT_23eedae60 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eedae60 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar5 = *(longlong **)(lVar11 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  plVar16 = (longlong *)plVar5[2];
  *(undefined4 *)(plVar5 + 8) = 0xffffffff;
  if (plVar16 != (longlong *)0x0) {
    plVar5[2] = 0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))();
    }
  }
  *plVar5 = *plVar5 + -1;
  if (*plVar5 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  plVar5[0xf] = 0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((pcVar15 != (code *)0x0) &&
     (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 == 0)) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
  }
  lVar11 = *plVar1;
  *plVar1 = lVar11 + -1;
  if (lVar11 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar11 = *plVar2;
  *plVar2 = lVar11 + -1;
  if (lVar11 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plStack_98,plStack_90,plVar18);
  return (code *)0x0;
}
