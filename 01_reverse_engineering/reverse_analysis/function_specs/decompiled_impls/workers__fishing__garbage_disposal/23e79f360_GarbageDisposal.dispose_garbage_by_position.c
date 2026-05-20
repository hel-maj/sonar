/* ===== 23e79f360 workers.fishing.garbage_disposal:399 ===== */
/* ghidra_name=FUN_23e79f360 entry=23e79f360 size=10441 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e79f360(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  code **********ppppppppppcVar3;
  code *********pppppppppcVar4;
  code ************ppppppppppppcVar5;
  undefined8 *puVar6;
  code ***********pppppppppppcVar7;
  code **********ppppppppppcVar8;
  code *******pppppppcVar9;
  undefined8 uVar10;
  code ***********pppppppppppcVar11;
  code ******ppppppcVar12;
  int iVar13;
  code *************pppppppppppppcVar14;
  code *************pppppppppppppcVar15;
  longlong *plVar16;
  code *************pppppppppppppcVar17;
  undefined8 uVar18;
  code ************ppppppppppppcVar19;
  longlong *plVar20;
  longlong lVar21;
  longlong lVar22;
  code *************pppppppppppppcVar23;
  longlong *plVar24;
  code ************ppppppppppppcVar25;
  code *pcVar26;
  longlong *plVar27;
  code *************pppppppppppppcVar28;
  code ***********pppppppppppcVar29;
  int iVar30;
  undefined4 uVar31;
  code *************pppppppppppppcStack_100;
  code *************pppppppppppppcStack_f0;
  code *************pppppppppppppcStack_e8;
  code *pcStack_e0;
  code *pcStack_d8;
  code *************pppppppppppppcStack_a8;
  code *******pppppppcStack_a0;
  undefined1 auStack_98 [16];
  code ***********apppppppppppcStack_88 [2];
  code *************pppppppppppppcStack_78;
  code *************pppppppppppppcStack_70;
  code ************ppppppppppppcStack_68;
  
  pppppppppppcVar29 = _DAT_23eedabe0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eedabe0 == (code ***********)0x0) {
LAB_23e79f3ae:
    _DAT_23eedabe0 = (code ***********)FUN_23e91f3b0(param_1,DAT_23eedabd8,DAT_23eedacf8,0x40);
  }
  else {
    ppppppppppcVar3 = *_DAT_23eedabe0;
    if (1 < (longlong)ppppppppppcVar3) {
      *_DAT_23eedabe0 = (code **********)((longlong)ppppppppppcVar3 + -1);
      goto LAB_23e79f3ae;
    }
    if (_DAT_23eedabe0[2] != (code **********)0x0) {
      *_DAT_23eedabe0 = (code **********)((longlong)ppppppppppcVar3 + -1);
      if ((code **********)((longlong)ppppppppppcVar3 + -1) == (code **********)0x0) {
        (*(code *)pppppppppppcVar29[1][6])(pppppppppppcVar29);
      }
      goto LAB_23e79f3ae;
    }
  }
  pppppppppppcVar11 = _DAT_23eedabe0;
  lVar21 = *(longlong *)(param_1 + 0x38);
  pppppppppppcVar29 = _DAT_23eedabe0 + 9;
  ppppppppppcVar3 = *(code ***********)(lVar21 + 8);
  _DAT_23eedabe0[0xf] = ppppppppppcVar3;
  *(code ************)(lVar21 + 8) = pppppppppppcVar29;
  if ((ppppppppppcVar3 != (code **********)0x0) &&
     (((*(char *)((longlong)ppppppppppcVar3 + 0x45) == '\x01' ||
       ((code *********)
        ((longlong)ppppppppppcVar3[4] + (longlong)*(int *)(ppppppppppcVar3[4] + 0x15) * 2 + 0xb8) <=
        ppppppppppcVar3[7])) && (pppppppppppcVar11[0xe] != (code **********)0x0)))) {
    pppppppppcVar4 = ppppppppppcVar3[5];
    pppppppppppcVar11[0xe][2] = pppppppppcVar4;
    if (pppppppppcVar4 != (code *********)0x0) {
      *pppppppppcVar4 = (code ********)((longlong)*pppppppppcVar4 + 1);
    }
  }
  *pppppppppppcVar11 = (code **********)((longlong)*pppppppppppcVar11 + 1);
  *(undefined4 *)(pppppppppppcVar11 + 8) = 0;
  pppppppppppppcVar14 = (code *************)FUN_23a38cc10(param_1,plVar2,DAT_23ed6ce48);
  if (pppppppppppppcVar14 == (code *************)0x0) {
    pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
    ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (ppppppppppppcVar19 != (code ************)0x0) {
      if (ppppppppppppcVar19[3] == pppppppppppcVar11) {
        plVar16 = (longlong *)0x0;
        pppppppppppppcVar17 = (code *************)0x0;
        pppppppppppppcVar15 = (code *************)0x0;
        pppppppppppppcStack_100 = (code *************)0x0;
        ppppppppppppcVar25 = ppppppppppppcVar19;
        goto LAB_23e7a01c0;
      }
      plVar16 = (longlong *)0x0;
      pppppppppppppcVar17 = (code *************)0x0;
      pppppppppppppcVar15 = (code *************)0x0;
      pppppppppppppcStack_100 = (code *************)0x0;
      uVar31 = 0x194;
      pcStack_e0 = _PyRuntime_exref;
      goto LAB_23e7a03c0;
    }
    plVar16 = (longlong *)0x0;
    pppppppppppppcVar17 = (code *************)0x0;
    pppppppppppppcVar15 = (code *************)0x0;
    pppppppppppppcStack_100 = (code *************)0x0;
    iVar13 = 0x194;
    pcStack_e0 = _PyRuntime_exref;
    goto LAB_23e7a0610;
  }
  pppppppppppppcVar15 = (code *************)FUN_23a38cc10(param_1,plVar2,DAT_23eed8338);
  if (pppppppppppppcVar15 == (code *************)0x0) {
    pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
    ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (ppppppppppppcVar19 == (code ************)0x0) {
      plVar16 = (longlong *)0x0;
      pppppppppppppcVar17 = (code *************)0x0;
      iVar13 = 0x195;
      pppppppppppppcStack_100 = (code *************)0x0;
      pcStack_e0 = _PyRuntime_exref;
      goto LAB_23e7a0610;
    }
    if (ppppppppppppcVar19[3] == pppppppppppcVar11) {
      pppppppppppppcStack_100 = (code *************)0x0;
      plVar16 = (longlong *)0x0;
      pppppppppppppcVar17 = (code *************)0x0;
      ppppppppppppcVar25 = ppppppppppppcVar19;
      goto LAB_23e7a01c0;
    }
    plVar16 = (longlong *)0x0;
    pppppppppppppcVar17 = (code *************)0x0;
    uVar31 = 0x195;
    pppppppppppppcStack_100 = (code *************)0x0;
    pcStack_e0 = _PyRuntime_exref;
  }
  else {
    pppppppppppppcStack_100 = (code *************)FUN_23a38cc10(param_1,plVar2,DAT_23eed8410);
    if (pppppppppppppcStack_100 == (code *************)0x0) {
      pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
      ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (ppppppppppppcVar19 == (code ************)0x0) {
        plVar16 = (longlong *)0x0;
        pppppppppppppcVar17 = (code *************)0x0;
        iVar13 = 0x196;
        pcStack_e0 = _PyRuntime_exref;
        goto LAB_23e7a0610;
      }
      if (ppppppppppppcVar19[3] == pppppppppppcVar11) {
        plVar16 = (longlong *)0x0;
        pppppppppppppcVar17 = (code *************)0x0;
        ppppppppppppcVar25 = ppppppppppppcVar19;
        goto LAB_23e7a01c0;
      }
      plVar16 = (longlong *)0x0;
      pppppppppppppcVar17 = (code *************)0x0;
      uVar31 = 0x196;
      pcStack_e0 = _PyRuntime_exref;
    }
    else {
      plVar16 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23ed6ce40);
      if (plVar16 != (longlong *)0x0) {
        *(undefined4 *)(pppppppppppcVar11 + 5) = 0x197;
        pppppppppppppcVar17 = (code *************)FUN_23e9557e0(param_1,plVar16,_DAT_23eed8580);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        if (pppppppppppppcVar17 == (code *************)0x0) {
          pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
          ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (ppppppppppppcVar19 != (code ************)0x0) {
            if (pppppppppppcVar11 != ppppppppppppcVar19[3]) {
              plVar16 = (longlong *)0x0;
              uVar31 = 0x197;
              pcStack_e0 = _PyRuntime_exref;
              goto LAB_23e7a03c0;
            }
LAB_23e7a01b0:
            plVar16 = (longlong *)0x0;
            ppppppppppppcVar25 = ppppppppppppcVar19;
            goto LAB_23e7a01c0;
          }
LAB_23e7a0e28:
          pcStack_e0 = _PyRuntime_exref;
          plVar16 = (longlong *)0x0;
          iVar13 = 0x197;
        }
        else {
          iVar13 = FUN_23a35f020(pppppppppppppcVar17);
          if (iVar13 == -1) {
            pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
            ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (ppppppppppppcVar19 == (code ************)0x0) {
              plVar16 = (longlong *)0x0;
              iVar13 = 0x199;
              pcStack_e0 = _PyRuntime_exref;
              goto LAB_23e7a0610;
            }
            if (ppppppppppppcVar19[3] == pppppppppppcVar11) goto LAB_23e7a01b0;
            pcStack_e0 = _PyRuntime_exref;
            plVar16 = (longlong *)0x0;
            uVar31 = 0x199;
            goto LAB_23e7a03c0;
          }
          if (iVar13 == 0) {
            uVar18 = FUN_23a3a0d40(DAT_23ed6cf28);
            ppppppppppppcVar19 = _DAT_23eed8588;
            lVar21 = *(longlong *)(param_1 + 0x10);
            pppppppppppppcVar23 = *(code **************)(lVar21 + 0xe20);
            if (pppppppppppppcVar23 == (code *************)0x0) {
              pppppppppppppcVar23 = (code *************)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              ppppppppppppcVar25 = pppppppppppppcVar23[3];
              *(int *)(lVar21 + 0xebc) = *(int *)(lVar21 + 0xebc) + -1;
              *(code *************)(lVar21 + 0xe20) = ppppppppppppcVar25;
              *pppppppppppppcVar23 = (code ************)0x1;
            }
            pcStack_e0 = _PyRuntime_exref;
            pppppppppppppcVar23[4] = (code ************)0x0;
            ppppppppppppcVar25 =
                 *(code *************)
                  (*(longlong *)(*(longlong *)(pcStack_e0 + 0x1f8) + 0x10) + 0x2e8);
            ppppppppppppcVar5 = pppppppppppppcVar23[-1];
            pppppppppppcVar29 = ppppppppppppcVar25[1];
            *pppppppppppcVar29 = (code **********)(pppppppppppppcVar23 + -2);
            pppppppppppppcVar23[-2] = ppppppppppppcVar25;
            pppppppppppppcVar23[-1] =
                 (code ************)
                 ((ulonglong)((uint)ppppppppppppcVar5 & 3) | (ulonglong)pppppppppppcVar29);
            ppppppppppppcVar25[1] = (code ***********)(pppppppppppppcVar23 + -2);
            plVar16 = DAT_23ed6a4c0;
            *ppppppppppppcVar19 = (code ***********)((longlong)*ppppppppppppcVar19 + 1);
            pppppppppppppcVar23[3] = ppppppppppppcVar19;
            pppppppcVar9 = DAT_23ed6cd28;
            if (plVar16 == (longlong *)0x0) {
              plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              pppppppppppppcStack_e8 = pppppppppppppcVar23;
              if (plVar16 != (longlong *)0x0) {
                *plVar16 = *plVar16 + 1;
                DAT_23ed6a4c0 = plVar16;
                goto LAB_23e79f5c5;
              }
LAB_23e7a0e10:
              pppppppppppppcStack_f0 = (code *************)&DAT_23ed6a4c0;
              PyErr_PrintEx(0);
              Py_Exit(1);
              goto LAB_23e7a0e28;
            }
LAB_23e79f5c5:
            pppppppppppppcStack_70 = (code *************)pppppppcVar9;
            pppppppppppppcStack_78 = pppppppppppppcVar14;
            ppppppppppppcVar19 =
                 (code ************)FUN_23e94ed00(param_1,plVar16,&pppppppppppppcStack_78);
            if (ppppppppppppcVar19 != (code ************)0x0) {
              pppppppppppppcVar23[4] = ppppppppppppcVar19;
              pcStack_d8 = PyUnicode_Join_exref;
              plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pppppppppppppcVar23);
              *pppppppppppppcVar23 = (code ************)((longlong)*pppppppppppppcVar23 + -1);
              if (*pppppppppppppcVar23 == (code ************)0x0) {
                (*(code *)pppppppppppppcVar23[1][6])(pppppppppppppcVar23);
              }
              if (plVar16 == (longlong *)0x0) {
                pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
                ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto joined_r0x00023e7a0a65;
              }
              *(undefined4 *)(pppppppppppcVar11 + 5) = 0x19c;
              plVar20 = (longlong *)FUN_23e914090(param_1,uVar18,plVar16);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              if (plVar20 != (longlong *)0x0) goto LAB_23e79f690;
              pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
              ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (ppppppppppppcVar19 != (code ************)0x0) {
                if (pppppppppppcVar11 == ppppppppppppcVar19[3]) goto LAB_23e7a01b0;
                plVar16 = (longlong *)0x0;
                uVar31 = 0x19c;
                goto LAB_23e7a03c0;
              }
LAB_23e7a0cef:
              plVar16 = (longlong *)0x0;
              iVar13 = 0x19c;
              goto LAB_23e7a0610;
            }
            pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
            ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *pppppppppppppcVar23 = (code ************)((longlong)*pppppppppppppcVar23 + -1);
            plVar16 = (longlong *)0x0;
            if (*pppppppppppppcVar23 == (code ************)0x0) {
              (*(code *)pppppppppppppcVar23[1][6])(pppppppppppppcVar23);
joined_r0x00023e7a0a65:
              if (ppppppppppppcVar19 == (code ************)0x0) goto LAB_23e7a0cef;
              uVar31 = 0x19c;
            }
            else {
              uVar31 = 0x19c;
              iVar13 = 0x19c;
              if (ppppppppppppcVar19 == (code ************)0x0) goto LAB_23e7a0610;
            }
LAB_23e7a076f:
            plVar16 = (longlong *)0x0;
            ppppppppppppcVar25 = ppppppppppppcVar19;
            if (pppppppppppcVar11 == ppppppppppppcVar19[3]) goto LAB_23e7a01c0;
            goto LAB_23e7a03c0;
          }
          uVar18 = FUN_23a3a0d40(DAT_23ed6cf28);
          ppppppppppppcVar19 = _DAT_23eed8588;
          lVar21 = *(longlong *)(param_1 + 0x10);
          pppppppppppppcVar23 = *(code **************)(lVar21 + 0xe30);
          if (pppppppppppppcVar23 == (code *************)0x0) {
            pppppppppppppcVar23 = (code *************)FUN_23e916a20(PyTuple_Type_exref,4);
          }
          else {
            ppppppppppppcVar25 = pppppppppppppcVar23[3];
            *(int *)(lVar21 + 0xec4) = *(int *)(lVar21 + 0xec4) + -1;
            *(code *************)(lVar21 + 0xe30) = ppppppppppppcVar25;
            *pppppppppppppcVar23 = (code ************)0x1;
          }
          pcStack_e0 = _PyRuntime_exref;
          pppppppppppppcVar23[6] = (code ************)0x0;
          *(undefined1 (*) [16])(pppppppppppppcVar23 + 4) = (undefined1  [16])0x0;
          ppppppppppppcVar25 =
               *(code *************)
                (*(longlong *)(*(longlong *)(pcStack_e0 + 0x1f8) + 0x10) + 0x2e8);
          ppppppppppppcVar5 = pppppppppppppcVar23[-1];
          pppppppppppcVar29 = ppppppppppppcVar25[1];
          *pppppppppppcVar29 = (code **********)(pppppppppppppcVar23 + -2);
          pppppppppppppcVar23[-2] = ppppppppppppcVar25;
          pppppppppppppcVar23[-1] =
               (code ************)
               ((ulonglong)((uint)ppppppppppppcVar5 & 3) | (ulonglong)pppppppppppcVar29);
          ppppppppppppcVar25[1] = (code ***********)(pppppppppppppcVar23 + -2);
          plVar16 = DAT_23ed6a4c0;
          *ppppppppppppcVar19 = (code ***********)((longlong)*ppppppppppppcVar19 + 1);
          pppppppppppppcVar23[3] = ppppppppppppcVar19;
          pppppppcVar9 = DAT_23ed6cd28;
          if (plVar16 == (longlong *)0x0) {
            plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            pppppppppppppcStack_e8 = pppppppppppppcVar23;
            if (plVar16 == (longlong *)0x0) goto LAB_23e7a0e10;
            *plVar16 = *plVar16 + 1;
            DAT_23ed6a4c0 = plVar16;
          }
          pppppppppppppcStack_70 = (code *************)pppppppcVar9;
          pppppppppppppcStack_78 = pppppppppppppcVar14;
          ppppppppppppcVar19 =
               (code ************)FUN_23e94ed00(param_1,plVar16,&pppppppppppppcStack_78);
          if (ppppppppppppcVar19 == (code ************)0x0) {
LAB_23e7a0160:
            pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
            ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *pppppppppppppcVar23 = (code ************)((longlong)*pppppppppppppcVar23 + -1);
            if (*pppppppppppppcVar23 == (code ************)0x0) {
              (*(code *)pppppppppppppcVar23[1][6])(pppppppppppppcVar23);
              if (ppppppppppppcVar19 == (code ************)0x0) goto LAB_23e7a0103;
              pppppppppppcVar29 = ppppppppppppcVar19[3];
            }
            else {
joined_r0x00023e7a0193:
              if (ppppppppppppcVar19 == (code ************)0x0) {
LAB_23e7a0103:
                plVar16 = (longlong *)0x0;
                iVar13 = 0x19a;
                goto LAB_23e7a0610;
              }
              pppppppppppcVar29 = ppppppppppppcVar19[3];
            }
            if (pppppppppppcVar11 == pppppppppppcVar29) goto LAB_23e7a01b0;
            plVar16 = (longlong *)0x0;
            uVar31 = 0x19a;
            goto LAB_23e7a03c0;
          }
          pppppppppppppcVar23[4] = ppppppppppppcVar19;
          ppppppppppppcVar19 = _DAT_23eed8590;
          *_DAT_23eed8590 = (code ***********)((longlong)*_DAT_23eed8590 + 1);
          pppppppppppppcVar23[5] = ppppppppppppcVar19;
          pppppppcVar9 = DAT_23ed6cd28;
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            pppppppppppppcStack_e8 = (code *************)&pppppppppppppcStack_78;
            if (plVar16 == (longlong *)0x0) goto LAB_23e7a0e10;
            *plVar16 = *plVar16 + 1;
            DAT_23ed6a4c0 = plVar16;
          }
          pppppppppppppcStack_e8 = (code *************)&pppppppppppppcStack_78;
          pppppppppppppcStack_70 = (code *************)pppppppcVar9;
          pppppppppppppcStack_78 = pppppppppppppcVar17;
          ppppppppppppcVar19 =
               (code ************)FUN_23e94ed00(param_1,DAT_23ed6a4c0,pppppppppppppcStack_e8);
          if (ppppppppppppcVar19 == (code ************)0x0) goto LAB_23e7a0160;
          pppppppppppppcVar23[6] = ppppppppppppcVar19;
          pcStack_d8 = PyUnicode_Join_exref;
          plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pppppppppppppcVar23);
          *pppppppppppppcVar23 = (code ************)((longlong)*pppppppppppppcVar23 + -1);
          if (*pppppppppppppcVar23 == (code ************)0x0) {
            (*(code *)pppppppppppppcVar23[1][6])(pppppppppppppcVar23);
          }
          if (plVar16 == (longlong *)0x0) {
            pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
            ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (ppppppppppppcVar19 != (code ************)0x0) {
              uVar31 = 0x19a;
              plVar16 = (longlong *)0x0;
              if (ppppppppppppcVar19[3] == pppppppppppcVar11) {
                plVar16 = (longlong *)0x0;
                ppppppppppppcVar25 = ppppppppppppcVar19;
                goto LAB_23e7a01c0;
              }
              goto LAB_23e7a03c0;
            }
            goto LAB_23e7a0103;
          }
          *(undefined4 *)(pppppppppppcVar11 + 5) = 0x19a;
          plVar20 = (longlong *)FUN_23e914090(param_1,uVar18,plVar16);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (plVar20 == (longlong *)0x0) {
            pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
            ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto joined_r0x00023e7a0193;
          }
LAB_23e79f690:
          pppppppppppppcStack_e8 = (code *************)&pppppppppppppcStack_78;
          *plVar20 = *plVar20 + -1;
          if (*plVar20 == 0) {
            (**(code **)(plVar20[1] + 0x30))(plVar20);
          }
          uVar18 = FUN_23a3a0d40(DAT_23ed6cf28);
          plVar20 = _DAT_23eed8598;
          lVar21 = *(longlong *)(param_1 + 0x10);
          plVar16 = *(longlong **)(lVar21 + 0xe38);
          if (plVar16 == (longlong *)0x0) {
            plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,5);
          }
          else {
            lVar22 = plVar16[3];
            *(int *)(lVar21 + 0xec8) = *(int *)(lVar21 + 0xec8) + -1;
            *(longlong *)(lVar21 + 0xe38) = lVar22;
            *plVar16 = 1;
          }
          *(undefined1 (*) [16])(plVar16 + 4) = (undefined1  [16])0x0;
          lVar21 = *(longlong *)(pcStack_e0 + 0x1f8);
          *(undefined1 (*) [16])(plVar16 + 6) = (undefined1  [16])0x0;
          lVar21 = *(longlong *)(*(longlong *)(lVar21 + 0x10) + 0x2e8);
          lVar22 = plVar16[-1];
          puVar6 = *(undefined8 **)(lVar21 + 8);
          *puVar6 = plVar16 + -2;
          plVar16[-2] = lVar21;
          plVar16[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar6;
          *(longlong **)(lVar21 + 8) = plVar16 + -2;
          plVar24 = DAT_23ed6a4c0;
          *plVar20 = *plVar20 + 1;
          plVar16[3] = (longlong)plVar20;
          pppppppcVar9 = DAT_23ed6cd28;
          if (plVar24 == (longlong *)0x0) {
            plVar24 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar24 == (longlong *)0x0) goto LAB_23e7a0e10;
            *plVar24 = *plVar24 + 1;
            DAT_23ed6a4c0 = plVar24;
          }
          pppppppppppppcStack_70 = (code *************)pppppppcVar9;
          pppppppppppppcStack_78 = pppppppppppppcVar15;
          lVar21 = FUN_23e94ed00(param_1,plVar24,pppppppppppppcStack_e8);
          if (lVar21 == 0) {
LAB_23e7a05c0:
            pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
            ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            if (ppppppppppppcVar19 != (code ************)0x0) {
              pppppppppppcVar29 = ppppppppppppcVar19[3];
joined_r0x00023e7a0867:
              if (pppppppppppcVar29 == pppppppppppcVar11) goto LAB_23e7a01b0;
              plVar16 = (longlong *)0x0;
              uVar31 = 0x19d;
              goto LAB_23e7a03c0;
            }
          }
          else {
            plVar16[4] = lVar21;
            plVar20 = DAT_23eed8558;
            *DAT_23eed8558 = *DAT_23eed8558 + 1;
            plVar16[5] = (longlong)plVar20;
            pppppppcVar9 = DAT_23ed6cd28;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar20 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar20 == (longlong *)0x0) goto LAB_23e7a0e10;
              *plVar20 = *plVar20 + 1;
              DAT_23ed6a4c0 = plVar20;
            }
            pppppppppppppcStack_70 = (code *************)pppppppcVar9;
            pppppppppppppcStack_78 = pppppppppppppcStack_100;
            lVar21 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pppppppppppppcStack_e8);
            if (lVar21 == 0) goto LAB_23e7a05c0;
            plVar16[6] = lVar21;
            plVar20 = _DAT_23eed85a0;
            *_DAT_23eed85a0 = *_DAT_23eed85a0 + 1;
            plVar16[7] = (longlong)plVar20;
            plVar20 = (longlong *)(*pcStack_d8)(DAT_23ed6cd28,plVar16);
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            if (plVar20 != (longlong *)0x0) {
              *(undefined4 *)(pppppppppppcVar11 + 5) = 0x19d;
              plVar16 = (longlong *)FUN_23e914090(param_1,uVar18,plVar20);
              *plVar20 = *plVar20 + -1;
              if (*plVar20 == 0) {
                (**(code **)(plVar20[1] + 0x30))(plVar20);
              }
              if (plVar16 != (longlong *)0x0) {
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                uVar18 = FUN_23a3a0d40(DAT_23ed6cf28);
                *(undefined4 *)(pppppppppppcVar11 + 5) = 0x1a0;
                plVar16 = (longlong *)FUN_23e94bb80(param_1,uVar18,_DAT_23eed85a8);
                if (plVar16 == (longlong *)0x0) {
                  pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
                  ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (ppppppppppppcVar19 != (code ************)0x0) {
                    uVar31 = 0x1a0;
                    plVar16 = (longlong *)0x0;
                    if (pppppppppppcVar11 == ppppppppppppcVar19[3]) {
                      plVar16 = (longlong *)0x0;
                      ppppppppppppcVar25 = ppppppppppppcVar19;
                      goto LAB_23e7a01c0;
                    }
                    goto LAB_23e7a03c0;
                  }
                  iVar13 = 0x1a0;
                  plVar16 = (longlong *)0x0;
                  goto LAB_23e7a0610;
                }
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed82a8);
                ppppppppppppcVar19 = _DAT_23eed8270;
                if (plVar16 == (longlong *)0x0) {
                  pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
                  ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (ppppppppppppcVar19 != (code ************)0x0) {
                    uVar31 = 0x1a1;
                    plVar16 = (longlong *)0x0;
                    if (ppppppppppppcVar19[3] == pppppppppppcVar11) {
                      plVar16 = (longlong *)0x0;
                      ppppppppppppcVar25 = ppppppppppppcVar19;
                      goto LAB_23e7a01c0;
                    }
                    goto LAB_23e7a03c0;
                  }
                }
                else {
                  *(undefined4 *)(pppppppppppcVar11 + 5) = 0x1a1;
                  ppppppppppppcStack_68 = ppppppppppppcVar19;
                  pppppppppppppcStack_78 = pppppppppppppcVar15;
                  pppppppppppppcStack_70 = pppppppppppppcStack_100;
                  plVar20 = (longlong *)
                            FUN_23e9578c0(param_1,plVar16,DAT_23eed85b0,pppppppppppppcStack_e8);
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                  }
                  if (plVar20 != (longlong *)0x0) {
                    iVar13 = FUN_23a35f020(plVar20);
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      (**(code **)(plVar20[1] + 0x30))(plVar20);
                    }
                    if (iVar13 != -1) {
                      if (iVar13 == 0) {
                        uVar18 = FUN_23a3a0d40(DAT_23ed6cf28);
                        *(undefined4 *)(pppppppppppcVar11 + 5) = 0x1a2;
                        plVar16 = (longlong *)FUN_23e94bb80(param_1,uVar18,_DAT_23eed85b8);
                        if (plVar16 == (longlong *)0x0) {
                          pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
                          ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          if (ppppppppppppcVar19 == (code ************)0x0) {
                            iVar13 = 0x1a2;
                            plVar16 = (longlong *)0x0;
                            goto LAB_23e7a0610;
                          }
                          uVar31 = 0x1a2;
                          plVar16 = (longlong *)0x0;
                          if (pppppppppppcVar11 == ppppppppppppcVar19[3]) {
                            plVar16 = (longlong *)0x0;
                            ppppppppppppcVar25 = ppppppppppppcVar19;
                            goto LAB_23e7a01c0;
                          }
                          goto LAB_23e7a03c0;
                        }
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          (**(code **)(plVar16[1] + 0x30))(plVar16);
                        }
                        pcVar26 = _Py_FalseStruct_exref;
                        plVar16 = (longlong *)0x0;
                        *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23e7a0901:
                        lVar21 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                        plVar20 = *(longlong **)(lVar21 + 0x28);
                        plVar24 = (longlong *)plVar20[2];
                        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                             *(undefined8 *)(lVar21 + 0x30);
                        *(undefined4 *)(plVar20 + 8) = 0xffffffff;
                        if (plVar24 != (longlong *)0x0) {
                          plVar20[2] = 0;
                          *plVar24 = *plVar24 + -1;
                          if (*plVar24 == 0) {
                            (**(code **)(plVar24[1] + 0x30))();
                          }
                        }
                        *plVar20 = *plVar20 + -1;
                        if (*plVar20 == 0) {
                          (**(code **)(plVar20[1] + 0x30))(plVar20);
                        }
                        plVar20[0xf] = 0;
LAB_23e7a0955:
                        *pppppppppppppcVar14 =
                             (code ************)((longlong)*pppppppppppppcVar14 + -1);
                        if (*pppppppppppppcVar14 == (code ************)0x0) {
                          (*(code *)pppppppppppppcVar14[1][6])(pppppppppppppcVar14);
                        }
                        *pppppppppppppcVar15 =
                             (code ************)((longlong)*pppppppppppppcVar15 + -1);
                        if (*pppppppppppppcVar15 == (code ************)0x0) {
                          (*(code *)pppppppppppppcVar15[1][6])(pppppppppppppcVar15);
                        }
                        ppppppppppppcVar19 = *pppppppppppppcStack_100;
                        *pppppppppppppcStack_100 =
                             (code ************)((longlong)ppppppppppppcVar19 + -1);
                        if ((code ************)((longlong)ppppppppppppcVar19 + -1) ==
                            (code ************)0x0) {
                          (*(code *)pppppppppppppcStack_100[1][6])(pppppppppppppcStack_100);
                        }
                        *pppppppppppppcVar17 =
                             (code ************)((longlong)*pppppppppppppcVar17 + -1);
                        if (*pppppppppppppcVar17 == (code ************)0x0) {
                          (*(code *)pppppppppppppcVar17[1][6])(pppppppppppppcVar17);
                        }
                        if ((plVar16 != (longlong *)0x0) &&
                           (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                          (**(code **)(plVar16[1] + 0x30))(plVar16);
                        }
                        lVar21 = *plVar1;
                        *plVar1 = lVar21 + -1;
                        if (lVar21 + -1 == 0) {
                          (**(code **)(plVar1[1] + 0x30))(plVar1);
                        }
                        *plVar2 = *plVar2 + -1;
                        if (*plVar2 != 0) {
                          return pcVar26;
                        }
                        (**(code **)(plVar2[1] + 0x30))(plVar2);
                        return pcVar26;
                      }
                      lVar22 = FUN_23e8df810();
                      lVar21 = _DAT_23eed85c0;
                      if (lVar22 == 0) {
                        FUN_23e915740(param_1,pppppppppppppcStack_e8,_DAT_23eed8258);
                        pppppppppppppcStack_e8 = pppppppppppppcStack_78;
                        pppppppppppppcStack_f0 = pppppppppppppcStack_70;
                        if (ppppppppppppcStack_68 != (code ************)0x0) {
                          uVar31 = 0x1a6;
                          plVar16 = (longlong *)0x0;
                          ppppppppppppcVar19 = ppppppppppppcStack_68;
                          if (ppppppppppppcStack_68[3] == pppppppppppcVar11) {
                            plVar16 = (longlong *)0x0;
                            ppppppppppppcVar25 = ppppppppppppcStack_68;
                            goto LAB_23e7a01c0;
                          }
                          goto LAB_23e7a03c0;
                        }
                      }
                      else {
                        *(undefined4 *)(pppppppppppcVar11 + 5) = 0x1a6;
                        plVar16 = (longlong *)
                                  FUN_23e915840(param_1,lVar22,_DAT_23eed8260,
                                                *(undefined8 *)(lVar21 + 0x18));
                        if (plVar16 != (longlong *)0x0) {
                          *plVar16 = *plVar16 + -1;
                          if (*plVar16 == 0) {
                            (**(code **)(plVar16[1] + 0x30))(plVar16);
                          }
                          uVar18 = FUN_23a3a0d40(DAT_23ed6cf28);
                          plVar20 = _DAT_23eed85c8;
                          lVar21 = *(longlong *)(param_1 + 0x10);
                          plVar16 = *(longlong **)(lVar21 + 0xe28);
                          if (plVar16 == (longlong *)0x0) {
                            plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                          }
                          else {
                            lVar22 = plVar16[3];
                            *(int *)(lVar21 + 0xec0) = *(int *)(lVar21 + 0xec0) + -1;
                            *(longlong *)(lVar21 + 0xe28) = lVar22;
                            *plVar16 = 1;
                          }
                          *(undefined1 (*) [16])(plVar16 + 4) = (undefined1  [16])0x0;
                          lVar21 = *(longlong *)
                                    (*(longlong *)(*(longlong *)(pcStack_e0 + 0x1f8) + 0x10) + 0x2e8
                                    );
                          lVar22 = plVar16[-1];
                          puVar6 = *(undefined8 **)(lVar21 + 8);
                          *puVar6 = plVar16 + -2;
                          plVar16[-2] = lVar21;
                          plVar16[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar6;
                          *(longlong **)(lVar21 + 8) = plVar16 + -2;
                          uVar10 = _DAT_23eed82f8;
                          *plVar20 = *plVar20 + 1;
                          plVar16[3] = (longlong)plVar20;
                          pppppppppppppcVar23 = (code *************)FUN_23e8bc2f0(plVar1,uVar10);
                          pppppppcVar9 = DAT_23ed6cd28;
                          if (pppppppppppppcVar23 == (code *************)0x0) {
LAB_23e7a0f11:
                            pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
                            ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar16 = *plVar16 + -1;
                            if (*plVar16 == 0) {
                              (**(code **)(plVar16[1] + 0x30))(plVar16);
                              if (ppppppppppppcVar19 == (code ************)0x0) {
LAB_23e7a18d8:
                                plVar16 = (longlong *)0x0;
                                iVar13 = 0x1a7;
                                goto LAB_23e7a0610;
                              }
                              pppppppppppcVar29 = ppppppppppppcVar19[3];
                            }
                            else {
                              if (ppppppppppppcVar19 == (code ************)0x0) goto LAB_23e7a18d8;
                              pppppppppppcVar29 = ppppppppppppcVar19[3];
                            }
                            if (pppppppppppcVar29 == pppppppppppcVar11) goto LAB_23e7a01b0;
                          }
                          else {
                            if (DAT_23ed6a4c0 == (longlong *)0x0) {
                              plVar20 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                              if (plVar20 == (longlong *)0x0) goto LAB_23e7a0e10;
                              *plVar20 = *plVar20 + 1;
                              DAT_23ed6a4c0 = plVar20;
                            }
                            pppppppppppppcStack_70 = (code *************)pppppppcVar9;
                            pppppppppppppcStack_78 = pppppppppppppcVar23;
                            lVar21 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pppppppppppppcStack_e8);
                            *pppppppppppppcVar23 =
                                 (code ************)((longlong)*pppppppppppppcVar23 + -1);
                            if (*pppppppppppppcVar23 == (code ************)0x0) {
                              (*(code *)pppppppppppppcVar23[1][6])(pppppppppppppcVar23);
                            }
                            if (lVar21 == 0) goto LAB_23e7a0f11;
                            plVar16[4] = lVar21;
                            plVar20 = _DAT_23eed85d0;
                            *_DAT_23eed85d0 = *_DAT_23eed85d0 + 1;
                            plVar16[5] = (longlong)plVar20;
                            plVar20 = (longlong *)(*pcStack_d8)(DAT_23ed6cd28,plVar16);
                            *plVar16 = *plVar16 + -1;
                            if (*plVar16 == 0) {
                              (**(code **)(plVar16[1] + 0x30))(plVar16);
                            }
                            if (plVar20 != (longlong *)0x0) {
                              *(undefined4 *)(pppppppppppcVar11 + 5) = 0x1a7;
                              plVar16 = (longlong *)FUN_23e914090(param_1,uVar18);
                              *plVar20 = *plVar20 + -1;
                              if (*plVar20 == 0) {
                                (**(code **)(plVar20[1] + 0x30))(plVar20);
                              }
                              if (plVar16 == (longlong *)0x0) {
                                pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
                                ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                if (ppppppppppppcVar19 != (code ************)0x0) {
                                  pppppppppppcVar29 = ppppppppppppcVar19[3];
                                  goto joined_r0x00023e7a1911;
                                }
                                goto LAB_23e7a18d8;
                              }
                              *plVar16 = *plVar16 + -1;
                              if (*plVar16 == 0) {
                                (**(code **)(plVar16[1] + 0x30))(plVar16);
                              }
                              plVar20 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eed82f8);
                              plVar16 = (longlong *)0x0;
                              if (plVar20 == (longlong *)0x0) {
LAB_23e7a1011:
                                ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                                pppppppppppppcVar23 = *(code **************)(param_1 + 0x60);
                                pppppppppppppcVar28 = *(code **************)(param_1 + 0x68);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                pppppppppppppcStack_e8._0_4_ = 0x1aa;
                              }
                              else {
                                plVar24 = (longlong *)FUN_23e8bc2f0(plVar20,DAT_23ed6ce98);
                                *plVar20 = *plVar20 + -1;
                                if (*plVar20 == 0) {
                                  (**(code **)(plVar20[1] + 0x30))(plVar20);
                                }
                                if (plVar24 == (longlong *)0x0) {
                                  pppppppppppppcVar23 = *(code **************)(param_1 + 0x60);
                                  pppppppppppppcVar28 = *(code **************)(param_1 + 0x68);
                                  ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                                  plVar16 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  pppppppppppppcStack_e8._0_4_ = 0x1aa;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23e7a102f;
                                }
                                *(undefined4 *)(pppppppppppcVar11 + 5) = 0x1aa;
                                plVar16 = (longlong *)FUN_23e91a870(param_1);
                                *plVar24 = *plVar24 + -1;
                                if (*plVar24 == 0) {
                                  (**(code **)(plVar24[1] + 0x30))(plVar24);
                                }
                                if (plVar16 == (longlong *)0x0) goto LAB_23e7a1011;
                                plVar20 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed82a8);
                                if (plVar20 != (longlong *)0x0) {
                                  iVar13 = FUN_23e8be270(param_1,plVar20,_DAT_23eed85d8);
                                  *plVar20 = *plVar20 + -1;
                                  if (*plVar20 == 0) {
                                    (**(code **)(plVar20[1] + 0x30))(plVar20);
                                  }
                                  if (iVar13 != -1) {
                                    if (iVar13 == 0) {
                                      lVar21 = FUN_23e8df6c0();
                                      if (lVar21 == 0) {
                                        FUN_23e915740(param_1,pppppppppppppcStack_e8,_DAT_23eed8248)
                                        ;
                                        pppppppppppppcStack_e8._0_4_ = 0x1b1;
                                        ppppppppppppcVar19 = ppppppppppppcStack_68;
                                        pppppppppppppcVar23 = pppppppppppppcStack_78;
                                        pppppppppppppcVar28 = pppppppppppppcStack_70;
                                      }
                                      else {
                                        *(undefined4 *)(pppppppppppcVar11 + 5) = 0x1b1;
                                        plVar20 = (longlong *)
                                                  FUN_23e915840(param_1,lVar21,_DAT_23eed85e0,
                                                                plVar16);
                                        if (plVar20 != (longlong *)0x0) {
                                          *plVar20 = *plVar20 + -1;
                                          if (*plVar20 == 0) {
                                            FUN_23a334bc0(plVar20);
                                          }
                                          goto LAB_23e79fcee;
                                        }
                                        pppppppppppppcVar23 = *(code **************)(param_1 + 0x60)
                                        ;
                                        ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        pppppppppppppcStack_e8._0_4_ = 0x1b1;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        pppppppppppppcVar28 = *(code **************)(param_1 + 0x68)
                                        ;
                                      }
                                      goto LAB_23e7a102f;
                                    }
                                    plVar20 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed82a8);
                                    if (plVar20 != (longlong *)0x0) {
                                      *(undefined4 *)(pppppppppppcVar11 + 5) = 0x1ae;
                                      plVar24 = (longlong *)
                                                FUN_23e915840(param_1,plVar20,_DAT_23eed85d8);
                                      *plVar20 = *plVar20 + -1;
                                      if (*plVar20 == 0) {
                                        FUN_23a334bc0(plVar20);
                                      }
                                      if (plVar24 != (longlong *)0x0) {
                                        *plVar24 = *plVar24 + -1;
                                        if (*plVar24 == 0) {
                                          FUN_23a334bc0(plVar24);
                                        }
LAB_23e79fcee:
                                        lVar22 = FUN_23e8df810();
                                        lVar21 = _DAT_23eed85c0;
                                        if (lVar22 == 0) {
                                          FUN_23e915740(param_1,pppppppppppppcStack_e8,
                                                        _DAT_23eed8258);
                                          pppppppppppppcStack_e8._0_4_ = 0x1b4;
                                          ppppppppppppcVar19 = ppppppppppppcStack_68;
                                          pppppppppppppcVar23 = pppppppppppppcStack_78;
                                          pppppppppppppcVar28 = pppppppppppppcStack_70;
                                        }
                                        else {
                                          *(undefined4 *)(pppppppppppcVar11 + 5) = 0x1b4;
                                          plVar20 = (longlong *)
                                                    FUN_23e915840(param_1,lVar22,_DAT_23eed8260,
                                                                  *(undefined8 *)(lVar21 + 0x18));
                                          if (plVar20 == (longlong *)0x0) {
                                            pppppppppppppcVar23 =
                                                 *(code **************)(param_1 + 0x60);
                                            ppppppppppppcVar19 =
                                                 *(code *************)(param_1 + 0x70);
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            pppppppppppppcStack_e8._0_4_ = 0x1b4;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            pppppppppppppcVar28 =
                                                 *(code **************)(param_1 + 0x68);
                                          }
                                          else {
                                            *plVar20 = *plVar20 + -1;
                                            if (*plVar20 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            uVar18 = FUN_23a3a0d40(DAT_23ed6cf28);
                                            plVar20 = _DAT_23eed85e8;
                                            plVar24 = (longlong *)
                                                      FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),
                                                                    5);
                                            *plVar20 = *plVar20 + 1;
                                            plVar24[3] = (longlong)plVar20;
                                            lVar21 = FUN_23e94f9d0(param_1,pppppppppppppcVar14,
                                                                   DAT_23ed6cd28);
                                            if (lVar21 != 0) {
                                              plVar24[4] = lVar21;
                                              plVar20 = _DAT_23eed85f0;
                                              *_DAT_23eed85f0 = *_DAT_23eed85f0 + 1;
                                              plVar24[5] = (longlong)plVar20;
                                              lVar21 = FUN_23e94f9d0(param_1,plVar16,DAT_23ed6cd28);
                                              if (lVar21 != 0) {
                                                plVar24[6] = lVar21;
                                                plVar20 = _DAT_23eed85f8;
                                                *_DAT_23eed85f8 = *_DAT_23eed85f8 + 1;
                                                plVar24[7] = (longlong)plVar20;
                                                plVar20 = (longlong *)
                                                          (*pcStack_d8)(DAT_23ed6cd28,plVar24);
                                                *plVar24 = *plVar24 + -1;
                                                if (*plVar24 == 0) {
                                                  FUN_23a334bc0(plVar24);
                                                }
                                                if (plVar20 != (longlong *)0x0) {
                                                  *(undefined4 *)(pppppppppppcVar11 + 5) = 0x1b5;
                                                  plVar24 = (longlong *)
                                                            FUN_23e914090(param_1,uVar18);
                                                  *plVar20 = *plVar20 + -1;
                                                  if (*plVar20 == 0) {
                                                    FUN_23a334bc0(plVar20);
                                                  }
                                                  if (plVar24 != (longlong *)0x0) {
                                                    *plVar24 = *plVar24 + -1;
                                                    if (*plVar24 == 0) {
                                                      FUN_23a334bc0(plVar24);
                                                    }
                                                    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                                    pcVar26 = _Py_TrueStruct_exref;
                                                    *(longlong *)_Py_TrueStruct_exref =
                                                         *(longlong *)_Py_TrueStruct_exref + 1;
                                                    goto LAB_23e7a0955;
                                                  }
                                                }
                                                pppppppppppppcVar23 =
                                                     *(code **************)(param_1 + 0x60);
                                                ppppppppppppcVar19 =
                                                     *(code *************)(param_1 + 0x70);
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                pppppppppppppcStack_e8._0_4_ = 0x1b5;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                pppppppppppppcVar28 =
                                                     *(code **************)(param_1 + 0x68);
                                                goto LAB_23e7a102f;
                                              }
                                            }
                                            pppppppppppppcVar23 =
                                                 *(code **************)(param_1 + 0x60);
                                            pppppppppppppcVar28 =
                                                 *(code **************)(param_1 + 0x68);
                                            ppppppppppppcVar19 =
                                                 *(code *************)(param_1 + 0x70);
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            pppppppppppppcStack_e8._0_4_ = 0x1b5;
                                            *plVar24 = *plVar24 + -1;
                                            if (*plVar24 == 0) {
                                              FUN_23a334bc0(plVar24);
                                              pppppppppppppcStack_e8._0_4_ = 0x1b5;
                                            }
                                          }
                                        }
                                        goto LAB_23e7a102f;
                                      }
                                    }
                                    pppppppppppppcVar23 = *(code **************)(param_1 + 0x60);
                                    ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    pppppppppppppcStack_e8._0_4_ = 0x1ae;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    pppppppppppppcVar28 = *(code **************)(param_1 + 0x68);
                                    goto LAB_23e7a102f;
                                  }
                                }
                                pppppppppppppcVar23 = *(code **************)(param_1 + 0x60);
                                pppppppppppppcVar28 = *(code **************)(param_1 + 0x68);
                                ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                                pppppppppppppcStack_e8._0_4_ = 0x1ad;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              }
LAB_23e7a102f:
                              plVar20 = *(longlong **)(param_1 + 0x138);
                              auStack_98._8_8_ = pppppppppppppcVar28;
                              auStack_98._0_8_ = pppppppppppppcVar23;
                              if (plVar20 != (longlong *)0x0) {
                                *plVar20 = *plVar20 + 1;
                              }
                              pppppppppppcVar29 = (code ***********)DAT_23ed6a4f8;
                              apppppppppppcStack_88[0] = (code ***********)ppppppppppppcVar19;
                              if (ppppppppppppcVar19 == (code ************)0x0) {
                                if (DAT_23ed6a4f8 == (code ******)0x0) {
                                  pppppppppppcVar29 =
                                       (code ***********)FUN_23a33a530(PyTraceBack_Type_exref);
                                }
                                else {
                                  ppppppcVar12 = (code ******)*DAT_23ed6a4f8;
                                  *DAT_23ed6a4f8 = (code *****)0x1;
                                  DAT_23ed6a4f8 = ppppppcVar12;
                                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                                }
                                pppppppppppcVar29[2] = (code **********)0x0;
                                pppppppppppcVar29[3] = (code **********)pppppppppppcVar11;
                                *pppppppppppcVar11 =
                                     (code **********)((longlong)*pppppppppppcVar11 + 1);
                                lVar21 = *(longlong *)(pcStack_e0 + 0x1f8);
                                *(undefined4 *)((longlong)pppppppppppcVar29 + 0x24) =
                                     pppppppppppppcStack_e8._0_4_;
                                lVar21 = *(longlong *)(lVar21 + 0x10);
                                *(undefined4 *)(pppppppppppcVar29 + 4) = 0xffffffff;
                                ppppppppppcVar3 = *(code ***********)(lVar21 + 0x2e8);
                                ppppppppppcVar8 = pppppppppppcVar29[-1];
                                pppppppppcVar4 = ppppppppppcVar3[1];
                                *pppppppppcVar4 = (code ********)(pppppppppppcVar29 + -2);
                                pppppppppppcVar29[-2] = ppppppppppcVar3;
                                pppppppppppcVar29[-1] =
                                     (code **********)
                                     ((ulonglong)((uint)ppppppppppcVar8 & 3) |
                                     (ulonglong)pppppppppcVar4);
                                ppppppppppcVar3[1] = (code *********)(pppppppppppcVar29 + -2);
                                if ((apppppppppppcStack_88[0] != (code ***********)0x0) &&
                                   (*apppppppppppcStack_88[0] =
                                         (code **********)((longlong)*apppppppppppcStack_88[0] + -1)
                                   , (code ***********)*apppppppppppcStack_88[0] ==
                                     (code ***********)0x0)) {
                                  (*(code *)apppppppppppcStack_88[0][1][6])
                                            (apppppppppppcStack_88[0]);
                                }
                              }
                              else {
                                if (DAT_23ed6a4f8 == (code ******)0x0) {
                                  pppppppppppcVar29 =
                                       (code ***********)FUN_23a33a530(PyTraceBack_Type_exref);
                                }
                                else {
                                  ppppppcVar12 = (code ******)*DAT_23ed6a4f8;
                                  *DAT_23ed6a4f8 = (code *****)0x1;
                                  DAT_23ed6a4f8 = ppppppcVar12;
                                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                                }
                                pppppppppppcVar29[3] = (code **********)pppppppppppcVar11;
                                *pppppppppppcVar11 =
                                     (code **********)((longlong)*pppppppppppcVar11 + 1);
                                lVar21 = *(longlong *)(pcStack_e0 + 0x1f8);
                                *(undefined4 *)((longlong)pppppppppppcVar29 + 0x24) =
                                     pppppppppppppcStack_e8._0_4_;
                                *(undefined4 *)(pppppppppppcVar29 + 4) = 0xffffffff;
                                ppppppppppcVar3 =
                                     *(code ***********)(*(longlong *)(lVar21 + 0x10) + 0x2e8);
                                ppppppppppcVar8 = pppppppppppcVar29[-1];
                                pppppppppcVar4 = ppppppppppcVar3[1];
                                *pppppppppcVar4 = (code ********)(pppppppppppcVar29 + -2);
                                pppppppppppcVar29[-2] = ppppppppppcVar3;
                                pppppppppppcVar29[-1] =
                                     (code **********)
                                     ((ulonglong)((uint)ppppppppppcVar8 & 3) |
                                     (ulonglong)pppppppppcVar4);
                                ppppppppppcVar3[1] = (code *********)(pppppppppppcVar29 + -2);
                                pppppppppppcVar29[2] = (code **********)ppppppppppppcVar19;
                                *ppppppppppppcVar19 =
                                     (code ***********)((longlong)*ppppppppppppcVar19 + 1);
                                if ((apppppppppppcStack_88[0] != (code ***********)0x0) &&
                                   (*apppppppppppcStack_88[0] =
                                         (code **********)((longlong)*apppppppppppcStack_88[0] + -1)
                                   , (code ***********)*apppppppppppcStack_88[0] ==
                                     (code ***********)0x0)) {
                                  (*(code *)apppppppppppcStack_88[0][1][6])();
                                }
                              }
                              pcVar26 = _Py_NoneStruct_exref;
                              apppppppppppcStack_88[0] = pppppppppppcVar29;
                              if (((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) &&
                                 ((code *)auStack_98._0_8_ != (code *)0x0)) {
                                FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,
                                              apppppppppppcStack_88);
                              }
                              plVar24 = *(longlong **)(auStack_98._8_8_ + 0x28);
                              if (apppppppppppcStack_88[0] == (code ***********)pcVar26) {
                                pppppppppppcVar29 = (code ***********)0x0;
                              }
                              else {
                                pppppppppppcVar29 = apppppppppppcStack_88[0];
                                if (apppppppppppcStack_88[0] != (code ***********)0x0) {
                                  *apppppppppppcStack_88[0] =
                                       (code **********)((longlong)*apppppppppppcStack_88[0] + 1);
                                }
                              }
                              *(code ************)(auStack_98._8_8_ + 0x28) = pppppppppppcVar29;
                              if ((plVar24 != (longlong *)0x0) &&
                                 (*plVar24 = *plVar24 + -1, *plVar24 == 0)) {
                                (**(code **)(plVar24[1] + 0x30))();
                              }
                              plVar24 = *(longlong **)(param_1 + 0x138);
                              *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
                              if ((plVar24 != (longlong *)0x0) &&
                                 (*plVar24 = *plVar24 + -1, *plVar24 == 0)) {
                                (**(code **)(plVar24[1] + 0x30))();
                              }
                              *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
                              if (*(longlong *)auStack_98._0_8_ == 0) {
                                (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
                              }
                              if ((apppppppppppcStack_88[0] != (code ***********)0x0) &&
                                 (*apppppppppppcStack_88[0] =
                                       (code **********)((longlong)*apppppppppppcStack_88[0] + -1),
                                 *apppppppppppcStack_88[0] == (code **********)0x0)) {
                                (*(code *)apppppppppppcStack_88[0][1][6])();
                              }
                              apppppppppppcStack_88[0] = (code ***********)0x0;
                              auStack_98 = (undefined1  [16])0x0;
                              iVar13 = FUN_23a35ebd0(param_1,*(undefined8 *)
                                                              (*(longlong *)(param_1 + 0x138) + 8),
                                                     *(undefined8 *)PyExc_Exception_exref);
                              pppppppppppppcVar23 = *(code **************)(param_1 + 0x138);
                              if (iVar13 == 0) {
                                if ((pppppppppppppcVar23 == (code *************)pcVar26) ||
                                   (pppppppppppppcVar23 == (code *************)0x0)) {
                                  pppppppppppppcStack_e8 =
                                       *(code **************)PyExc_RuntimeError_exref;
                                  pppppppppppppcStack_f0 =
                                       (code *************)
                                       PyUnicode_FromString("No active exception to reraise");
                                  *pppppppppppppcStack_e8 =
                                       (code ************)((longlong)*pppppppppppppcStack_e8 + 1);
                                  plVar24 = *(longlong **)(param_1 + 0x138);
                                  iVar13 = 0x1a8;
                                  iVar30 = 0x1a8;
                                  *(longlong **)(param_1 + 0x138) = plVar20;
                                  if ((plVar24 == (longlong *)0x0) ||
                                     (*plVar24 = *plVar24 + -1, *plVar24 != 0)) goto LAB_23e7a0610;
LAB_23e7a1b45:
                                  (**(code **)(plVar24[1] + 0x30))();
                                  iVar13 = iVar30;
                                  if (iVar30 != 0) goto LAB_23e7a0610;
LAB_23e7a1b65:
                                  iVar13 = *(int *)(pppppppppppcVar11 + 5);
                                  goto LAB_23e7a0610;
                                }
                                pppppppppppppcStack_e8 = (code *************)pppppppppppppcVar23[1];
                                ppppppppppppcVar25 = pppppppppppppcVar23[5];
                                *pppppppppppppcVar23 =
                                     (code ************)((longlong)*pppppppppppppcVar23 + 1);
                                *pppppppppppppcStack_e8 =
                                     (code ************)((longlong)*pppppppppppppcStack_e8 + 1);
                                pppppppppppppcStack_f0 = pppppppppppppcVar23;
                                if (ppppppppppppcVar25 == (code ************)0x0) {
                                  plVar24 = *(longlong **)(param_1 + 0x138);
                                  *(longlong **)(param_1 + 0x138) = plVar20;
                                  if (plVar24 != (longlong *)0x0) {
                                    *plVar24 = *plVar24 + -1;
                                    iVar30 = 0;
                                    if (*plVar24 == 0) goto LAB_23e7a1b45;
                                  }
                                  goto LAB_23e7a1b65;
                                }
                                *ppppppppppppcVar25 =
                                     (code ***********)((longlong)*ppppppppppppcVar25 + 1);
                                if (ppppppppppppcVar25[3] == pppppppppppcVar11) {
                                  *(undefined4 *)(pppppppppppcVar11 + 5) =
                                       *(undefined4 *)((longlong)ppppppppppppcVar25 + 0x24);
                                }
                                *(longlong **)(param_1 + 0x138) = plVar20;
                                ppppppppppppcVar19 = *pppppppppppppcVar23;
                                *pppppppppppppcVar23 =
                                     (code ************)((longlong)ppppppppppppcVar19 + -1);
                                if ((code ************)((longlong)ppppppppppppcVar19 + -1) ==
                                    (code ************)0x0) {
                                  (*(code *)pppppppppppppcStack_e8[6])(pppppppppppppcVar23);
                                  iVar30 = 0;
                                  goto LAB_23e7a1799;
                                }
                                if (pppppppppppcVar11 == ppppppppppppcVar25[3]) goto LAB_23e7a01c0;
LAB_23e7a17ac:
                                uVar31 = *(undefined4 *)(pppppppppppcVar11 + 5);
                                ppppppppppppcVar19 = ppppppppppppcVar25;
                                goto LAB_23e7a03c0;
                              }
                              *pppppppppppppcVar23 =
                                   (code ************)((longlong)*pppppppppppppcVar23 + 1);
                              uVar18 = FUN_23a3a0d40(DAT_23ed6cf28);
                              ppppppppppppcVar19 = _DAT_23eed8600;
                              lVar21 = *(longlong *)(param_1 + 0x10);
                              pppppppppppppcVar28 = *(code **************)(lVar21 + 0xe30);
                              if (pppppppppppppcVar28 == (code *************)0x0) {
                                pppppppppppppcVar28 =
                                     (code *************)FUN_23e916a20(PyTuple_Type_exref,4);
                              }
                              else {
                                ppppppppppppcVar25 = pppppppppppppcVar28[3];
                                *(int *)(lVar21 + 0xec4) = *(int *)(lVar21 + 0xec4) + -1;
                                *(code *************)(lVar21 + 0xe30) = ppppppppppppcVar25;
                                *pppppppppppppcVar28 = (code ************)0x1;
                              }
                              pppppppppppppcVar28[6] = (code ************)0x0;
                              *(undefined1 (*) [16])(pppppppppppppcVar28 + 4) =
                                   (undefined1  [16])0x0;
                              ppppppppppppcVar25 =
                                   *(code *************)
                                    (*(longlong *)(*(longlong *)(pcStack_e0 + 0x1f8) + 0x10) + 0x2e8
                                    );
                              ppppppppppppcVar5 = pppppppppppppcVar28[-1];
                              pppppppppppcVar29 = ppppppppppppcVar25[1];
                              *pppppppppppcVar29 = (code **********)(pppppppppppppcVar28 + -2);
                              pppppppppppppcVar28[-2] = ppppppppppppcVar25;
                              pppppppppppppcVar28[-1] =
                                   (code ************)
                                   ((ulonglong)((uint)ppppppppppppcVar5 & 3) |
                                   (ulonglong)pppppppppppcVar29);
                              ppppppppppppcVar25[1] = (code ***********)(pppppppppppppcVar28 + -2);
                              uVar10 = _DAT_23eed82f8;
                              *ppppppppppppcVar19 =
                                   (code ***********)((longlong)*ppppppppppppcVar19 + 1);
                              pppppppppppppcVar28[3] = ppppppppppppcVar19;
                              pppppppppppppcStack_e8 =
                                   (code *************)FUN_23e8bc2f0(plVar1,uVar10);
                              pppppppcVar9 = DAT_23ed6cd28;
                              if (pppppppppppppcStack_e8 == (code *************)0x0) {
LAB_23e7a1545:
                                pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
                                ppppppppppppcVar25 = *(code *************)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *pppppppppppppcVar28 =
                                     (code ************)((longlong)*pppppppppppppcVar28 + -1);
                                if (*pppppppppppppcVar28 == (code ************)0x0) {
                                  (*(code *)pppppppppppppcVar28[1][6])(pppppppppppppcVar28);
                                }
                              }
                              else {
                                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                  plVar24 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format")
                                  ;
                                  if (plVar24 == (longlong *)0x0) goto LAB_23e7a0e10;
                                  *plVar24 = *plVar24 + 1;
                                  DAT_23ed6a4c0 = plVar24;
                                }
                                pppppppcStack_a0 = pppppppcVar9;
                                pppppppppppppcStack_a8 = pppppppppppppcStack_e8;
                                ppppppppppppcVar19 =
                                     (code ************)
                                     FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pppppppppppppcStack_a8);
                                *pppppppppppppcStack_e8 =
                                     (code ************)((longlong)*pppppppppppppcStack_e8 + -1);
                                if (*pppppppppppppcStack_e8 == (code ************)0x0) {
                                  (*(code *)pppppppppppppcStack_e8[1][6])(pppppppppppppcStack_e8);
                                }
                                if (ppppppppppppcVar19 == (code ************)0x0)
                                goto LAB_23e7a1545;
                                pppppppppppppcVar28[4] = ppppppppppppcVar19;
                                ppppppppppppcVar19 = _DAT_23eed8608;
                                *_DAT_23eed8608 = (code ***********)((longlong)*_DAT_23eed8608 + 1);
                                pppppppppppppcVar28[5] = ppppppppppppcVar19;
                                pppppppcVar9 = DAT_23ed6cd28;
                                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                  plVar24 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format")
                                  ;
                                  pppppppppppppcStack_e8 = pppppppppppppcVar28;
                                  if (plVar24 == (longlong *)0x0) goto LAB_23e7a0e10;
                                  *plVar24 = *plVar24 + 1;
                                  DAT_23ed6a4c0 = plVar24;
                                }
                                pppppppcStack_a0 = pppppppcVar9;
                                pppppppppppppcStack_a8 = pppppppppppppcVar23;
                                ppppppppppppcVar19 =
                                     (code ************)
                                     FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pppppppppppppcStack_a8);
                                if (ppppppppppppcVar19 == (code ************)0x0)
                                goto LAB_23e7a1545;
                                pppppppppppppcVar28[6] = ppppppppppppcVar19;
                                plVar24 = (longlong *)
                                          (*pcStack_d8)(DAT_23ed6cd28,pppppppppppppcVar28);
                                *pppppppppppppcVar28 =
                                     (code ************)((longlong)*pppppppppppppcVar28 + -1);
                                if (*pppppppppppppcVar28 == (code ************)0x0) {
                                  (*(code *)pppppppppppppcVar28[1][6])(pppppppppppppcVar28);
                                }
                                if (plVar24 != (longlong *)0x0) {
                                  *(undefined4 *)(pppppppppppcVar11 + 5) = 0x1b8;
                                  plVar27 = (longlong *)FUN_23e914090(param_1,uVar18);
                                  *plVar24 = *plVar24 + -1;
                                  if (*plVar24 == 0) {
                                    (**(code **)(plVar24[1] + 0x30))(plVar24);
                                  }
                                  if (plVar27 != (longlong *)0x0) {
                                    *plVar27 = *plVar27 + -1;
                                    if (*plVar27 == 0) {
                                      (**(code **)(plVar27[1] + 0x30))(plVar27);
                                    }
                                    pcVar26 = _Py_FalseStruct_exref;
                                    *(longlong *)_Py_FalseStruct_exref =
                                         *(longlong *)_Py_FalseStruct_exref + 1;
                                    ppppppppppppcVar19 = *pppppppppppppcVar23;
                                    *pppppppppppppcVar23 =
                                         (code ************)((longlong)ppppppppppppcVar19 + -1);
                                    if ((code ************)((longlong)ppppppppppppcVar19 + -1) ==
                                        (code ************)0x0) {
                                      (*(code *)pppppppppppppcVar23[1][6])(pppppppppppppcVar23);
                                    }
                                    plVar24 = *(longlong **)(param_1 + 0x138);
                                    *(longlong **)(param_1 + 0x138) = plVar20;
                                    if ((plVar24 != (longlong *)0x0) &&
                                       (*plVar24 = *plVar24 + -1, *plVar24 == 0)) {
                                      (**(code **)(plVar24[1] + 0x30))();
                                    }
                                    goto LAB_23e7a0901;
                                  }
                                }
                                pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
                                ppppppppppppcVar25 = *(code *************)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              }
                              ppppppppppppcVar19 = *pppppppppppppcVar23;
                              *pppppppppppppcVar23 =
                                   (code ************)((longlong)ppppppppppppcVar19 + -1);
                              if ((code ************)((longlong)ppppppppppppcVar19 + -1) ==
                                  (code ************)0x0) {
                                (*(code *)pppppppppppppcVar23[1][6])();
                              }
                              plVar24 = *(longlong **)(param_1 + 0x138);
                              *(longlong **)(param_1 + 0x138) = plVar20;
                              if (plVar24 == (longlong *)0x0) {
                                if (ppppppppppppcVar25 == (code ************)0x0) {
LAB_23e7a1c19:
                                  iVar13 = 0x1b8;
                                  goto LAB_23e7a0610;
                                }
                                pppppppppppcVar29 = ppppppppppppcVar25[3];
joined_r0x00023e7a1998:
                                if (pppppppppppcVar11 == pppppppppppcVar29) goto LAB_23e7a01c0;
                              }
                              else {
                                *plVar24 = *plVar24 + -1;
                                if (*plVar24 != 0) {
                                  if (ppppppppppppcVar25 == (code ************)0x0)
                                  goto LAB_23e7a1c19;
                                  pppppppppppcVar29 = ppppppppppppcVar25[3];
                                  goto joined_r0x00023e7a1998;
                                }
                                (**(code **)(plVar24[1] + 0x30))();
                                iVar13 = 0x1b8;
                                iVar30 = 0x1b8;
                                if (ppppppppppppcVar25 == (code ************)0x0)
                                goto LAB_23e7a0610;
LAB_23e7a1799:
                                if (ppppppppppppcVar25[3] == pppppppppppcVar11) goto LAB_23e7a01c0;
                                if (iVar30 == 0) goto LAB_23e7a17ac;
                              }
                              uVar31 = 0x1b8;
                              ppppppppppppcVar19 = ppppppppppppcVar25;
                              goto LAB_23e7a03c0;
                            }
                            pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
                            ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            if (ppppppppppppcVar19 == (code ************)0x0) goto LAB_23e7a18d8;
                            pppppppppppcVar29 = ppppppppppppcVar19[3];
joined_r0x00023e7a1911:
                            if (pppppppppppcVar29 == pppppppppppcVar11) goto LAB_23e7a1917;
                          }
                          plVar16 = (longlong *)0x0;
                          uVar31 = 0x1a7;
                          goto LAB_23e7a03c0;
                        }
                        pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
                        ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (ppppppppppppcVar19 != (code ************)0x0) {
                          if (pppppppppppcVar11 != ppppppppppppcVar19[3]) {
                            uVar31 = 0x1a6;
                            plVar16 = (longlong *)0x0;
                            goto LAB_23e7a03c0;
                          }
LAB_23e7a1917:
                          plVar16 = (longlong *)0x0;
                          ppppppppppppcVar25 = ppppppppppppcVar19;
                          goto LAB_23e7a01c0;
                        }
                      }
                      plVar16 = (longlong *)0x0;
                      iVar13 = 0x1a6;
                      goto LAB_23e7a0610;
                    }
                  }
                  pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
                  ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (ppppppppppppcVar19 != (code ************)0x0) {
                    if (pppppppppppcVar11 == ppppppppppppcVar19[3]) goto LAB_23e7a01b0;
                    plVar16 = (longlong *)0x0;
                    uVar31 = 0x1a1;
                    goto LAB_23e7a03c0;
                  }
                }
                plVar16 = (longlong *)0x0;
                iVar13 = 0x1a1;
                goto LAB_23e7a0610;
              }
              pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
              ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (ppppppppppppcVar19 == (code ************)0x0) goto LAB_23e7a05fc;
              pppppppppppcVar29 = ppppppppppppcVar19[3];
              goto joined_r0x00023e7a0867;
            }
            pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
            ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar31 = 0x19d;
            pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (ppppppppppppcVar19 != (code ************)0x0) goto LAB_23e7a076f;
          }
LAB_23e7a05fc:
          plVar16 = (longlong *)0x0;
          iVar13 = 0x19d;
        }
LAB_23e7a0610:
        ppppppppppppcVar25 = (code ************)DAT_23ed6a4f8;
        if (DAT_23ed6a4f8 == (code ******)0x0) {
          ppppppppppppcVar25 = (code ************)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          ppppppcVar12 = (code ******)*DAT_23ed6a4f8;
          *DAT_23ed6a4f8 = (code *****)0x1;
          DAT_23ed6a4f8 = ppppppcVar12;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        ppppppppppppcVar25[3] = pppppppppppcVar11;
        ppppppppppppcVar25[2] = (code ***********)0x0;
        *pppppppppppcVar11 = (code **********)((longlong)*pppppppppppcVar11 + 1);
        lVar21 = *(longlong *)(pcStack_e0 + 0x1f8);
        *(int *)((longlong)ppppppppppppcVar25 + 0x24) = iVar13;
        *(undefined4 *)(ppppppppppppcVar25 + 4) = 0xffffffff;
        pppppppppppcVar29 = *(code ************)(*(longlong *)(lVar21 + 0x10) + 0x2e8);
        pppppppppppcVar7 = ppppppppppppcVar25[-1];
        ppppppppppcVar3 = pppppppppppcVar29[1];
        *ppppppppppcVar3 = (code *********)(ppppppppppppcVar25 + -2);
        ppppppppppppcVar25[-2] = pppppppppppcVar29;
        ppppppppppppcVar25[-1] =
             (code ***********)
             ((ulonglong)((uint)pppppppppppcVar7 & 3) | (ulonglong)ppppppppppcVar3);
        pppppppppppcVar29[1] = (code **********)(ppppppppppppcVar25 + -2);
        goto LAB_23e7a01c0;
      }
      pppppppppppppcStack_e8 = *(code **************)(param_1 + 0x60);
      ppppppppppppcVar19 = *(code *************)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pppppppppppppcStack_f0 = *(code **************)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar16 = (longlong *)0x0;
      if (ppppppppppppcVar19 == (code ************)0x0) {
        pppppppppppppcVar17 = (code *************)0x0;
        iVar13 = 0x197;
        pcStack_e0 = _PyRuntime_exref;
        goto LAB_23e7a0610;
      }
      if (pppppppppppcVar11 == ppppppppppppcVar19[3]) {
        pppppppppppppcVar17 = (code *************)0x0;
        ppppppppppppcVar25 = ppppppppppppcVar19;
        goto LAB_23e7a01c0;
      }
      pppppppppppppcVar17 = (code *************)0x0;
      uVar31 = 0x197;
      pcStack_e0 = _PyRuntime_exref;
    }
  }
LAB_23e7a03c0:
  ppppppppppppcVar25 = (code ************)DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code ******)0x0) {
    ppppppppppppcVar25 = (code ************)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    ppppppcVar12 = (code ******)*DAT_23ed6a4f8;
    *DAT_23ed6a4f8 = (code *****)0x1;
    DAT_23ed6a4f8 = ppppppcVar12;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  ppppppppppppcVar25[3] = pppppppppppcVar11;
  *pppppppppppcVar11 = (code **********)((longlong)*pppppppppppcVar11 + 1);
  lVar21 = *(longlong *)(pcStack_e0 + 0x1f8);
  *(undefined4 *)((longlong)ppppppppppppcVar25 + 0x24) = uVar31;
  *(undefined4 *)(ppppppppppppcVar25 + 4) = 0xffffffff;
  pppppppppppcVar29 = *(code ************)(*(longlong *)(lVar21 + 0x10) + 0x2e8);
  pppppppppppcVar7 = ppppppppppppcVar25[-1];
  ppppppppppcVar3 = pppppppppppcVar29[1];
  *ppppppppppcVar3 = (code *********)(ppppppppppppcVar25 + -2);
  ppppppppppppcVar25[-2] = pppppppppppcVar29;
  ppppppppppppcVar25[-1] =
       (code ***********)((ulonglong)((uint)pppppppppppcVar7 & 3) | (ulonglong)ppppppppppcVar3);
  pppppppppppcVar7 = *ppppppppppppcVar19;
  pppppppppppcVar29[1] = (code **********)(ppppppppppppcVar25 + -2);
  ppppppppppppcVar25[2] = (code ***********)ppppppppppppcVar19;
  if (pppppppppppcVar7 == (code ***********)0x0) {
    (*(code *)ppppppppppppcVar19[1][6])(ppppppppppppcVar19);
  }
LAB_23e7a01c0:
  FUN_23e8bba40(pppppppppppcVar11,"oooooooo",plVar1,plVar2,pppppppppppppcVar14,pppppppppppppcVar15,
                pppppppppppppcStack_100,pppppppppppppcVar17,plVar16,0);
  if (_DAT_23eedabe0 == pppppppppppcVar11) {
    *pppppppppppcVar11 = (code **********)((longlong)*pppppppppppcVar11 + -1);
    if (*pppppppppppcVar11 == (code **********)0x0) {
      (*(code *)pppppppppppcVar11[1][6])(pppppppppppcVar11);
    }
    _DAT_23eedabe0 = (code ***********)0x0;
  }
  lVar21 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar20 = *(longlong **)(lVar21 + 0x28);
  plVar24 = (longlong *)plVar20[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar21 + 0x30);
  *(undefined4 *)(plVar20 + 8) = 0xffffffff;
  if (plVar24 != (longlong *)0x0) {
    plVar20[2] = 0;
    *plVar24 = *plVar24 + -1;
    if (*plVar24 == 0) {
      (**(code **)(plVar24[1] + 0x30))();
    }
  }
  *plVar20 = *plVar20 + -1;
  if (*plVar20 == 0) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  plVar20[0xf] = 0;
  if ((pppppppppppppcVar14 != (code *************)0x0) &&
     (*pppppppppppppcVar14 = (code ************)((longlong)*pppppppppppppcVar14 + -1),
     *pppppppppppppcVar14 == (code ************)0x0)) {
    (*(code *)pppppppppppppcVar14[1][6])(pppppppppppppcVar14);
  }
  if ((pppppppppppppcVar15 != (code *************)0x0) &&
     (*pppppppppppppcVar15 = (code ************)((longlong)*pppppppppppppcVar15 + -1),
     *pppppppppppppcVar15 == (code ************)0x0)) {
    (*(code *)pppppppppppppcVar15[1][6])(pppppppppppppcVar15);
  }
  if ((pppppppppppppcStack_100 != (code *************)0x0) &&
     (ppppppppppppcVar19 = *pppppppppppppcStack_100,
     *pppppppppppppcStack_100 = (code ************)((longlong)ppppppppppppcVar19 + -1),
     (code ************)((longlong)ppppppppppppcVar19 + -1) == (code ************)0x0)) {
    (*(code *)pppppppppppppcStack_100[1][6])(pppppppppppppcStack_100);
  }
  if ((pppppppppppppcVar17 != (code *************)0x0) &&
     (*pppppppppppppcVar17 = (code ************)((longlong)*pppppppppppppcVar17 + -1),
     *pppppppppppppcVar17 == (code ************)0x0)) {
    (*(code *)pppppppppppppcVar17[1][6])(pppppppppppppcVar17);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  lVar21 = *plVar1;
  *plVar1 = lVar21 + -1;
  if (lVar21 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,pppppppppppppcStack_e8,pppppppppppppcStack_f0,ppppppppppppcVar25);
  return (code *)0x0;
}
